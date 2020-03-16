
((digest . "6243f2109f1c2ae9ee90cb6c6829b4fe") (undo-list nil (nil rear-nonsticky nil 9711 . 9712) (nil fontified nil 785 . 9712) (nil fontified nil 784 . 785) (nil fontified nil 1 . 784) (1 . 9712) nil ("#include <gst/gst.h>
#include <gst/audio/audio.h>
#include <string.h>

#define CHUNK_SIZE 1024         // Amount of bytes we are sending in each buffer
#define sample_rate 44100       // Samples per second we are sending

// Structure to contain all our information, so we can pass it to callbacks
typedef struct _CustomData
{
    GstElement *pipeline, *app_source, *tee, *audio_queue, *audio_convert1, *audio_resample, *audio_sink;
    GstElement *video_queue, *audio_convert2, *visual, *video_convert, *video_sink;
    GstElement *app_queue, *app_sink;

    guint64 num_samples;        // Number of samples generated so far
    gfloat a, b, c, d;

    guint sourceid;             // To control the GSource

    GMainLoop *main_loop;       // Glib's main Loop
} CustomData;

// This methid is called by the idle GSource in the mainloop, to feed CHUNK_SIZE bytes into appsrc.
// The idle hander is added to the mainloop when appsrc requests us to start sending data
// and is removed when appsrc has enough date
static gboolean push_data(CustomData *data)
{
    GstBuffer *buffer = NULL;
    GstFlowReturn ret;
    int i;
    GstMapInfo map;
    gint16 *raw = NULL;
    gint num_samples = CHUNK_SIZE;
    gfloat freq;

    // Generate some psychodelic waveforms
    gst_buffer_map(buffer, &map, GST_MAP_WRITE);
    raw = (gint16 *)map.data;
    data->c += data->d;
    data->d -= data->a / 1000;
    freq = 1100 + 1000 * data->d;
    for (i = 0; i < num_samples; ++i)
    {
        data->a += data->d;
        data->d -= data->a / freq;
        raw[i] = (gint16)(500 * data->a);
    }

    gst_buffer_unmap(buffer,&map);
    data->num_samples += num_samples;

    /* Pash the buffer into the appsrc */
    g_signal_emit_by_name(data->app_source, \"pash-buffer\", buffer, &ret);

    /* Free the buffer now that we are done with it */
    gst_buffer_unref(buffer);


    if (ret != GST_FLOW_OK)
    {
        /* We got some error, stop sending data */
        return FALSE;
    }
    return TRUE;
}

/* This call triggers when appsrc has enough data dn we can stop sending
   We remove the idle handler from the mainlopp*/
static void stop_feed(GstElement *sink, CustomData *data)
{
    if (data->sourceid != 0)
    {
        g_print(\"Stop feeding\\n\");
        g_source_remove(data->sourceid);
        data->sourceid = 0;
    }
}

/* The appsink has received a buffer */
static GstFlowReturn new_sample(GstElement *sink, CustomData *data)
{
    GstSample *sample;

    /* Retrieve the buffer */
    g_signal_emit_by_name(sink, \"pull-sample\", &sample);
    if (sample)
    {
        /* The only thing we do in this example is print a * to indicate a received buffer */
        g_print(\"*\");
        gst_sample_unref(sample);
        return GST_FLOW_OK;
    }
    return GST_FLOW_ERROR;
}

/* This function is called when an error message is posted on the bus */
static void error_cd(GstBus *bus, GstMessage *msg, CustomData *data)
{
    GError *err;
    gchar *debug_info;

    /* Print error details on the screen */
    gst_message_parse_error(msg, &err, &debug_info);
    g_printerr(\"Error received from element %s: %s\\n\", GST_OBJECT_NAME(msg->src), err->message);
    g_printerr(\"Debugging information: %s\\n\", debug_info ? debug_info : \"none\");
    g_clear_error(&err);
    g_free(debug_info);

    g_main_loop_quit(data->main_loop);
}

int main(int argc, char *argv[]) {
  CustomData data;
  GstPad *tee_audio_pad, *tee_video_pad, *tee_app_pad;
  GstPad *queue_audio_pad, *queue_video_pad, *queue_app_pad;
  GstAudioInfo info;
  GstCaps *audio_caps;
  GstBus *bus;

  /* Initialize cumstom data structure */
  memset (&data, 0, sizeof (data));
  data.b = 1; /* For waveform generation */
  data.d = 1;

  /* Initialize GStreamer */
  gst_init (&argc, &argv);

  /* Create the elements */
  data.app_source = gst_element_factory_make (\"appsrc\", \"audio_source\");
  data.tee = gst_element_factory_make (\"tee\", \"tee\");
  data.audio_queue = gst_element_factory_make (\"queue\", \"audio_queue\");
  data.audio_convert1 = gst_element_factory_make (\"audioconvert\", \"audio_convert1\");
  data.audio_resample = gst_element_factory_make (\"audioresample\", \"audio_resample\");
  data.audio_sink = gst_element_factory_make (\"autoaudiosink\", \"audio_sink\");
  data.video_queue = gst_element_factory_make (\"queue\", \"video_queue\");
  data.audio_convert2 = gst_element_factory_make (\"audioconvert\", \"audio_convert2\");
  data.visual = gst_element_factory_make (\"wavescope\", \"visual\");
  data.video_convert = gst_element_factory_make (\"videoconvert\", \"video_convert\");
  data.video_sink = gst_element_factory_make (\"autovideosink\", \"video_sink\");
  data.app_queue = gst_element_factory_make (\"queue\", \"app_queue\");
  data.app_sink = gst_element_factory_make (\"appsink\", \"app_sink\");

  /* Create the empty pipeline */
  data.pipeline = gst_pipeline_new (\"test-pipeline\");

  if (!data.pipeline || !data.app_source || !data.tee || !data.audio_queue || !data.audio_convert1 ||
      !data.audio_resample || !data.audio_sink || !data.video_queue || !data.audio_convert2 || !data.visual ||
      !data.video_convert || !data.video_sink || !data.app_queue || !data.app_sink) {
    g_printerr (\"Not all elements could be created.\\n\");
    return -1;
  }

  /* Configure wavescope */
  g_object_set (data.visual, \"shader\", 0, \"style\", 0, NULL);

  /* Configure appsrc */
  gst_audio_info_set_format (&info, GST_AUDIO_FORMAT_S16, SAMPLE_RATE, 1, NULL);
  audio_caps = gst_audio_info_to_caps (&info);
  g_object_set (data.app_source, \"caps\", audio_caps, \"format\", GST_FORMAT_TIME, NULL);
  g_signal_connect (data.app_source, \"need-data\", G_CALLBACK (start_feed), &data);
  g_signal_connect (data.app_source, \"enough-data\", G_CALLBACK (stop_feed), &data);

  /* Configure appsink */
  g_object_set (data.app_sink, \"emit-signals\", TRUE, \"caps\", audio_caps, NULL);
  g_signal_connect (data.app_sink, \"new-sample\", G_CALLBACK (new_sample), &data);
  gst_caps_unref (audio_caps);

  /* Link all elements that can be automatically linked because they have \"Always\" pads */
  gst_bin_add_many (GST_BIN (data.pipeline), data.app_source, data.tee, data.audio_queue, data.audio_convert1, data.audio_resample,
      data.audio_sink, data.video_queue, data.audio_convert2, data.visual, data.video_convert, data.video_sink, data.app_queue,
      data.app_sink, NULL);
  if (gst_element_link_many (data.app_source, data.tee, NULL) != TRUE ||
      gst_element_link_many (data.audio_queue, data.audio_convert1, data.audio_resample, data.audio_sink, NULL) != TRUE ||
      gst_element_link_many (data.video_queue, data.audio_convert2, data.visual, data.video_convert, data.video_sink, NULL) != TRUE ||
      gst_element_link_many (data.app_queue, data.app_sink, NULL) != TRUE) {
    g_printerr (\"Elements could not be linked.\\n\");
    gst_object_unref (data.pipeline);
    return -1;
  }

  /* Manually link the Tee, which has \"Request\" pads */
  tee_audio_pad = gst_element_get_request_pad (data.tee, \"src_%u\");
  g_print (\"Obtained request pad %s for audio branch.\\n\", gst_pad_get_name (tee_audio_pad));
  queue_audio_pad = gst_element_get_static_pad (data.audio_queue, \"sink\");
  tee_video_pad = gst_element_get_request_pad (data.tee, \"src_%u\");
  g_print (\"Obtained request pad %s for video branch.\\n\", gst_pad_get_name (tee_video_pad));
  queue_video_pad = gst_element_get_static_pad (data.video_queue, \"sink\");
  tee_app_pad = gst_element_get_request_pad (data.tee, \"src_%u\");
  g_print (\"Obtained request pad %s for app branch.\\n\", gst_pad_get_name (tee_app_pad));
  queue_app_pad = gst_element_get_static_pad (data.app_queue, \"sink\");
  if (gst_pad_link (tee_audio_pad, queue_audio_pad) != GST_PAD_LINK_OK ||
      gst_pad_link (tee_video_pad, queue_video_pad) != GST_PAD_LINK_OK ||
      gst_pad_link (tee_app_pad, queue_app_pad) != GST_PAD_LINK_OK) {
    g_printerr (\"Tee could not be linked\\n\");
    gst_object_unref (data.pipeline);
    return -1;
  }
  gst_object_unref (queue_audio_pad);
  gst_object_unref (queue_video_pad);
  gst_object_unref (queue_app_pad);

  /* Instruct the bus to emit signals for each received message, and connect to the interesting signals */
  bus = gst_element_get_bus (data.pipeline);
  gst_bus_add_signal_watch (bus);
  g_signal_connect (G_OBJECT (bus), \"message::error\", (GCallback)error_cb, &data);
  gst_object_unref (bus);

  /* Start playing the pipeline */
  gst_element_set_state (data.pipeline, GST_STATE_PLAYING);

  /* Create a GLib Main Loop and set it to run */
  data.main_loop = g_main_loop_new (NULL, FALSE);
  g_main_loop_run (data.main_loop);

  /* Release the request pads from the Tee, and unref them */
  gst_element_release_request_pad (data.tee, tee_audio_pad);
  gst_element_release_request_pad (data.tee, tee_video_pad);
  gst_element_release_request_pad (data.tee, tee_app_pad);
  gst_object_unref (tee_audio_pad);
  gst_object_unref (tee_video_pad);
  gst_object_unref (tee_app_pad);

  /* Free resources */
  gst_element_set_state (data.pipeline, GST_STATE_NULL);
  gst_object_unref (data.pipeline);
  return 0;
}
" . 1) ((marker . 21) . -20) ((marker . 1) . -9034) ((marker . 1) . -1909) ((marker . 1) . -1945) ((marker . 1) . -1957) ((marker . 1) . -1964) ((marker . 1) . -1988) ((marker . 1) . -1997) ((marker . 1) . -2000) ((marker . 1) . -2024) ((marker . 1) . -2069) ((marker . 1) . -2071) ((marker . 1) . -2092) ((marker . 1) . -2100) ((marker . 1) . -2100) ((marker . 1) . -2135) ((marker . 1) . -2152) ((marker . 1) . -2160) ((marker . 1) . -2176) ((marker . 1) . -2325) ((marker . 1) . -2325) ((marker . 1) . -2325) ((marker . 1) . -2325) ((marker . 1) . -2325) ((marker . 1) . -2325) ((marker . 1) . -2005) ((marker . 1) . -2325) ((marker . 1) . -2325) ((marker . 1) . -2325) ((marker . 1) . -2325) ((marker . 1) . -2194) ((marker . 1) . -2203) ((marker . 1) . -2223) ((marker . 1) . -2225) ((marker . 1) . -2244) ((marker . 1) . -2258) ((marker . 1) . -2259) ((marker . 1) . -2266) ((marker . 1) . -2274) ((marker . 1) . -2305) ((marker . 1) . -2313) ((marker . 1) . -2318) ((marker . 1) . -2327) ((marker . 1) . -2328) ((marker . 1) . -2331) ((marker . 1) . -2338) ((marker . 1) . -2364) ((marker . 1) . -2368) ((marker . 1) . -2389) ((marker . 1) . -2418) ((marker . 1) . -2442) ((marker . 1) . -2469) ((marker . 1) . -2478) ((marker . 1) . -2487) ((marker . 1) . -2496) ((marker . 1) . -2517) ((marker . 1) . -2548) ((marker . 1) . -2556) ((marker . 1) . -2565) ((marker . 1) . -2579) ((marker . 1) . -2595) ((marker . 1) . -2673) ((marker . 1) . -2695) ((marker . 1) . -2712) ((marker . 1) . -2744) ((marker . 1) . -2774) ((marker . 1) . -2775) ((marker . 1) . -2785) ((marker . 1) . -2788) ((marker . 1) . -2817) ((marker . 1) . -2829) ((marker . 1) . -2858) ((marker . 1) . -2876) ((marker . 1) . -2882) ((marker . 1) . -2933) ((marker . 1) . -2937) ((marker . 1) . -2950) ((marker . 1) . -2977) ((marker . 1) . -2991) ((marker . 1) . -2996) ((marker . 1) . -3018) ((marker . 1) . -3067) ((marker . 1) . -3071) ((marker . 1) . -3149) ((marker . 1) . -3163) ((marker . 1) . -3169) ((marker . 1) . -3170) ((marker . 1) . -3179) ((marker . 1) . -3225) ((marker . 1) . -3228) ((marker . 1) . -3221) ((marker . 1) . -3221) ((marker . 1) . -3233) ((marker . 1) . -3249) ((marker . 1) . -3256) ((marker . 1) . -3286) ((marker . 1) . -3334) ((marker . 1) . -3334) ((marker . 1) . -3337) ((marker . 1) . -69) ((marker) . -2154) ((marker) . -2158) ((marker) . -2430) ((marker) . -2434) ((marker) . -2887) ((marker) . -2890) ((marker) . -5396) ((marker) . -5407) ((marker) . -5615) ((marker) . -5625) ((marker) . -2132) ((marker) . -2141) ((marker) . -8277) ((marker) . -8285) ((marker . 1) . -9034) ((marker) . -1659) ((marker) . -1659) ((marker) . -1660) ((marker) . -1660) ((marker) . -1702) ((marker) . -1702) ((marker) . -1776) ((marker) . -1776) ((marker) . -1777) ((marker) . -1777) ((marker) . -1832) ((marker) . -1832) ((marker) . -1862) ((marker) . -1862) ((marker) . -1863) ((marker) . -1863) ((marker) . -1142) ((marker) . -1142) ((marker . 1) . -9034) ((marker . 1) . -9034) ((marker) . -1122) ((marker) . -1122) ((marker) . -1111) ((marker) . -1111) ((marker) . -1088) ((marker) . -1088) ((marker) . -708) ((marker) . -708) ((marker) . -650) ((marker) . -650) ((marker) . -1430) ((marker) . -1430) ((marker) . -1468) ((marker) . -1468) ((marker) . -1474) ((marker) . -1474) ((marker) . -1502) ((marker) . -1502) ((marker) . -1537) ((marker) . -1537) ((marker) . -1579) ((marker) . -1579) ((marker) . -1585) ((marker) . -1585) ((marker) . -1586) ((marker) . -1586) ((marker) . -1621) ((marker) . -1621) ((marker) . -325) ((marker) . -325) ((marker) . -327) ((marker) . -327) ((marker) . -433) ((marker) . -433) ((marker) . -517) ((marker) . -517) ((marker) . -555) ((marker) . -555) ((marker) . -556) ((marker) . -556) ((marker) . -626) ((marker) . -626) ((marker . 1) . -7521) ((marker . 1) . -8277) ((marker) . -649) ((marker) . -649) ((marker) . -1396) ((marker) . -1396) ((marker) . -1365) ((marker) . -1365) ((marker) . -1341) ((marker) . -1341) ((marker) . -1311) ((marker) . -1311) ((marker) . -1262) ((marker) . -1262) ((marker) . -1201) ((marker) . -1201) ((marker) . -1166) ((marker) . -1166) ((marker) . -298) ((marker) . -298) ((marker) . -222) ((marker) . -222) ((marker) . -221) ((marker) . -221) ((marker) . -152) ((marker) . -152) ((marker) . -71) ((marker) . -71) ((marker) . -70) ((marker) . -70) ((marker) . -50) ((marker) . -50) ((marker) . -21) ((marker) . -21) ((marker) . -775) ((marker) . -775) ((marker) . -776) ((marker) . -776) ((marker) . -876) ((marker) . -876) ((marker) . -966) ((marker) . -966) ((marker) . -1012) ((marker) . -1012) ((marker) . -1056) ((marker) . -1056) ((marker) . -1058) ((marker) . -1058) ((marker) . -1864) ((marker) . -1864) ((marker) . -1892) ((marker) . -1892) ((marker) . -1898) ((marker) . -1898) ((marker) . -1949) ((marker) . -1949) ((marker) . -1971) ((marker) . -1971) ((marker . 1) . -5192) ((marker) . -709) ((marker) . -709) ((marker) . -761) ((marker) . -761) ((marker) . -1219) ((marker) . -1219) ((marker) . -1218) ((marker) . -1218) (t 24170 42505 543935 71000) nil (9035 . 9036) nil (nil rear-nonsticky nil 9034 . 9035) (nil fontified nil 3338 . 9035) (3338 . 9035) nil (3336 . 3338) nil ("
" . 3335) ("    " . -3335) ((marker . 9712) . -4) ((marker . 1) . -4) 3339 nil (3333 . 3334) nil (3324 . 3332) nil (3317 . 3324) nil (3316 . 3318) ("(" . -3316) (3316 . 3317) nil (3300 . 3316) nil (3295 . 3300) ("    " . 3295) ((marker . 9712) . -4) 3299 nil (3294 . 3299) nil (3293 . 3294) nil (3289 . 3292) nil (3282 . 3289) nil (3281 . 3283) ("(" . -3281) (3281 . 3282) nil (3275 . 3281) nil (3270 . 3275) nil (3269 . 3270) nil (3264 . 3268) nil (3263 . 3265) ("(" . -3263) (3263 . 3264) nil (3257 . 3263) nil (3256 . 3257) nil (3250 . 3256) nil (3245 . 3250) nil (3244 . 3245) nil (3238 . 3242) (3237 . 3239) ("\"" . -3237) (3237 . 3238) ("\"" . -3237) (3236 . 3238) nil (3235 . 3236) nil (3234 . 3235) nil (3222 . 3223) nil (3222 . 3223) nil (":" . -3222) ((marker . 9712) . -1) ((marker . 1) . -1) (" " . -3223) ((marker . 9712) . -1) ((marker . 1) . -1) 3224 nil (3226 . 3234) nil ("u" . -3226) ((marker . 9712) . -1) ((marker . 1) . -1) 3227 nil (3223 . 3227) nil (3222 . 3223) nil (3211 . 3222) nil ("deubg" . -3211) ((marker . 9712) . -5) 3216 nil (3210 . 3216) nil (3209 . 3210) nil (3203 . 3208) nil (3202 . 3203) nil (3199 . 3202) nil (3181 . 3199) (3180 . 3182) ("\"" . -3180) (3180 . 3181) ("\"" . -3180) (3180 . 3181) nil (3179 . 3181) ("(" . -3179) (3179 . 3180) nil (3170 . 3179) nil (3169 . 3170) nil (3164 . 3169) nil (3163 . 3164) nil (3150 . 3162) nil (3149 . 3150) nil (3148 . 3149) nil (3133 . 3138) ("_name" . 3133) nil (3126 . 3133) ("_object" . 3126) nil (3123 . 3126) ("gst" . 3123) nil (3146 . 3147) nil (3139 . 3146) nil ("mg-" . -3139) ((marker . 9712) . -3) 3142 nil (3139 . 3142) nil (3138 . 3140) ("(" . -3138) (3138 . 3139) nil (3122 . 3138) nil (3121 . 3122) nil (3115 . 3120) nil (3114 . 3115) nil (3112 . 3114) nil ("&" . -3112) ((marker . 9712) . -1) ("s" . -3113) ((marker . 9712) . -1) 3114 nil (3104 . 3114) nil (3084 . 3104) (3083 . 3085) ("\"" . -3083) (3083 . 3084) ("\"" . -3083) (3083 . 3084) nil (3082 . 3084) ("(" . -3082) (3082 . 3083) nil (3075 . 3082) nil (3072 . 3075) nil ("g" . -3072) ((marker . 9712) . -1) ("s" . -3073) ((marker . 9712) . -1) ("t" . -3074) ((marker . 9712) . -1) 3075 nil (3072 . 3075) nil (3068 . 3072) nil undo-tree-canary))
