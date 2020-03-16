
((digest . "3f72ac6e16b56065998a2670bd00de06") (undo-list nil (3670 . 3676) ("_print" . 3670) nil (3666 . 3670) ("
  g" . 3666) nil ("j" . -6049) ((marker . 1802) . -1) 6050 nil (6049 . 6050) (t 24171 19794 829286 665000) nil (64 . 74) nil (63 . 64) nil (56 . 63) nil ("pbutil" . -56) ((marker . 74) . -6) ((marker . 1802) . -6) ((marker . 56) . -1) 62 nil (56 . 62) nil (55 . 56) nil (43 . 55) nil (42 . 43) nil (41 . 42) nil (38 . 41) nil ("/" . -38) ((marker . 74) . -1) ((marker . 1802) . -1) ("h" . -39) ((marker . 74) . -1) ((marker . 1802) . -1) 40 nil (39 . 40) nil (38 . 39) nil (37 . 38) nil (35 . 37) nil (34 . 35) nil ("." . -34) ((marker . 74) . -1) ((marker . 1802) . -1) ("g" . -35) ((marker . 74) . -1) ((marker . 1802) . -1) 36 nil (22 . 36) nil (21 . 22) nil (20 . 21) nil (2 . 20) nil (1 . 2) nil (1 . 3) (t 24171 19738 510447 627000) nil (6081 . 6082) nil (nil rear-nonsticky nil 6080 . 6081) (nil fontified nil 5669 . 6081) (nil fontified nil 5668 . 5669) (nil fontified nil 5666 . 5668) (nil fontified nil 5665 . 5666) (nil fontified nil 4890 . 5665) (nil fontified nil 4889 . 4890) (nil fontified nil 4887 . 4889) (nil fontified nil 4886 . 4887) (nil fontified nil 3401 . 4886) (nil fontified nil 3400 . 3401) (nil fontified nil 3398 . 3400) (nil fontified nil 3397 . 3398) (nil fontified nil 2810 . 3397) (nil fontified nil 2809 . 2810) (nil fontified nil 2807 . 2809) (nil fontified nil 2806 . 2807) (nil fontified nil 1 . 2806) (1 . 6081) nil ("#include <string.h>
#include <gst/gst.h>
#include <gst/pbutils/pbutils.h>

/* Structure to contain all our information, so we can pass it around*/
typedef struct _CustomData
{
    GstDiscoverer *discoverer;
    GMainLoop *loop;
} CustomData;

/* Print a tag in a human-readable format (name: value) */
static void print_tag_foreach(const GstTagList *tags, const gchar *tag, gpointer user_data)
{
    GValue val = {0, };
    gchar *str;
    gint depth = GPOINTER_TO_INT(user_data);

    gst_tag_list_copy_value(&val, tags, tag);

    if (G_VALUE_HOLDS_STRING(&val))
        str = g_value_dup_string(&val);
    else
        str = gst_value_serialize(&val);

    g_print(\"%*s%s: %s\\n\", 2 * depth, \" \", gst_tag_get_nick(tag), str);
    g_free(str);

    g_value_unset(&val);
}

/* Print information regarding a stream*/
static void print_stream_info(GstDiscovererStreamInfo *info, gint depth)
{
    gchar *desc = NULL;
    GstCaps *caps;
    const GstTagList *tags;

    caps = gst_discoverer_stream_info_get_caps(info);

    if (caps)
    {
        if (gst_caps_is_fixed(caps))
            desc = gst_pb_utils_get_codec_description(info);
        else
            desc = gst_caps_to_string(caps);
        gst_caps_unref(caps);
    }

    g_print(\"%*s%s: %s\\n\", 2 * depth, \" \", gst_discoverer_stream_info_get_stream_type_nick(info), (desc ? desc : \"none\"));

    if (desc)
    {
        g_free(desc);
        desc = NULL;
    }

    tags = gst_discoverer_stream_info_get_tags(info);

    if (tags)
    {
        g_print(\"%*sTags:\\n\", 2 * (depth + 1), \" \");
        gst_tag_list_foreach(tags,print_tag_foreach, GINT_TO_POINTER(depth + 2));
        
    }
}


/* Print information regarding a stream and its substreams, if any */
static void print_topology(GstDiscovererStreamInfo *info, gint depth)
{
    GstDiscovererStreamInfo *next;

    if (!info)
    {
        return;
    }

    print_stream_info(info, depth);

    next = gst_discoverer_stream_info_get_next(info);
    if (next)
    {
        print_topology (next, depth + 1);
        gst_discoverer_stream_info_unref(next);
    }
    else if (GST_IS_DISCOVERER_CONTAINER_INFO(info))
    {
        GList *tmp, *streams;

        streams = gst_discoverer_container_info_get_streams(GST_DISCOVERER_CONTAINER_INFO(info));
        for (tmp = streams; tmp; tmp = tmp->next)
        {
            GstDiscovererStreamInfo *tmpinf = (GstDiscovererStreamInfo *)tmp->data;
            print_topology(tmpinf, depth+1);
        }
        gst_discoverer_stream_info_list_free(streams);
    }
}

/* This function is called every time the discoverer has information regarding
 one of the URIs we provided.*/
static void on_discovered_cb(GstDiscoverer *discoverer, GstDiscovererInfo *info, GError *err, CustomData *data)
{
    GstDiscovererResult result;
    const gchar *uri;
    const GstTagList *tags;
    GstDiscovererStreamInfo *sinfo;

    uri = gst_discoverer_info_get_uri(info);
    result = gst_discoverer_info_get_result(info);

    switch (result)
    {
    case GST_DISCOVERER_URI_INVALID:
        g_print(\"Invalid URI '%s'\\n\", uri);
        break;
    case GST_DISCOVERER_ERROR:
        g_print(\"Discoverer error: %s\\n\", err->message);
        break;
    case GST_DISCOVERER_TIMEOUT:
        g_print(\"Timeout\\n\");
        break;
    case GST_DISCOVERER_BUSY:
        g_print(\"Busy\\n\");
        break;

        // <----------
    case GST_DISCOVERER_MISSING_PLUGINS:
        {
            const GstStructure *s;
            gchar *str;

            s = gst_discoverer_info_get_misc(info);
            str = gst_structure_to_string(s);

            g_print(\"Missing plugins: %s\\n\", str);
            g_free(str);
        
            break;
        }
        // ---------->

    case GST_DISCOVERER_OK:
        g_print(\"Discovererd '%s'\\n\", uri);
        break;
    }

    if (result != GST_DISCOVERER_OK)
    {
        g_printerr(\"This URI cannot be played\\n\");
        return;
    }

    /* If we got no error, show the retrieved information */
    g_print(\"\\nDuration: %\" GST_TIME_FORMAT \"\\n\", GST_TIME_ARGS(gst_discoverer_info_get_duration(info)));

    tags = gst_discoverer_info_get_tags(info);
    if (tags)
    {
        g_print(\"Tags:\\n\");
        gst_tag_list_foreach(tags, print_tag_foreach, GINT_TO_POINTER(1));
    }

    g_print(\"Seekable: %s\\n\", (gst_discoverer_info_get_seekable(info) ? \"yes\" : \"no\"));
    g_print(\"\\n\");

    sinfo = gst_discoverer_info_get_stream_info(info);
    if (!sinfo)
        return;

    g_print(\"Stream information:\\n\");

    print_topology(sinfo, 1);
    gst_discoverer_stream_info_unref(sinfo);
    g_print(\"\\n\");
}

/* This function is called when the discoverer has finished examining
 all the URIs we provided.*/
static void on_finished_cb(GstDiscoverer *discoverer, CustomData *data)
{
    g_print(\"Finished discovering\\n\");

    g_main_loop_quit(data->loop);
}

int main(int argc, char **argv)
{
    CustomData data;
    GError *err = NULL;
    gchar *uri =  \"https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm\";

    /* If a URI was provided, use it instead of the default one */
    if (argc > 1)
    {
        uri = argv[1];
    }

    /* Initialize custom data structure */
    memset(&data, 0, sizeof(data));

    /* Initialize GStreamer */
    gst_init(&argc, &argv);

    g_print(\"Discovering '%s'\\n\", uri);

    /* Instantiate the Discoverer */
    data.discoverer = gst_discoverer_new(5 * GST_SECOND, &err);
    if (!data.discoverer)
    {
        g_print(\"Error creating discoverer instance: %s\\n\", err->message);
        g_clear_error(&err);
        exit(-1);
    }

    /* Connect to the interesting signals */
    g_signal_connect(data.discoverer, \"dicovererd\", G_CALLBACK(on_discovered_cb), &data);
    g_signal_connect(data.discoverer, \"finished\", G_CALLBACK(on_finished_cb), &data);

    /* Start the discoverer process (nothing to do yet) */
    gst_discoverer_start(data.discoverer);

    /* Add a request to process asynchronously the URI passed through the command line */
    if (!gst_discoverer_discover_uri_async(data.discoverer, uri))
    {
        g_print(\"Failed to start discovering URI '%s'\\n\", uri);
        g_object_unref(data.discoverer);
        exit (-1);
    }

    /* Create the GLib Main Loop and set it to run, so we can wait for the signals */
    data.loop = g_main_loop_new(NULL, FALSE);
    g_main_loop_run(data.loop);

    /* Stop the discovere process */
    gst_discoverer_stop(data.discoverer);

    /* Free resources */
    g_object_unref(data.discoverer);
    g_main_loop_unref(data.loop);

    return 0;
}
" . 1) ((marker . 74) . -19) ((marker . 3676) . -6588) ((marker . 1) . -4386) ((marker . 1) . -6586) ((marker . 1) . -6036) ((marker . 1) . -4347) ((marker . 1) . -4348) ((marker . 1) . -4390) ((marker . 1) . -4393) ((marker . 1) . -4398) ((marker . 1) . -4539) ((marker . 1) . -4603) ((marker . 1) . -4675) ((marker . 1) . -4692) ((marker . 1) . -4787) ((marker . 1) . -4813) ((marker . 1) . -4856) ((marker . 1) . -4860) ((marker . 1) . -4898) ((marker . 1) . -4919) ((marker . 1) . -4936) ((marker . 1) . -4950) ((marker . 1) . -4956) ((marker . 1) . -5046) ((marker . 1) . -5052) ((marker . 1) . -5078) ((marker . 1) . -5147) ((marker . 1) . -5161) ((marker . 1) . -5176) ((marker . 1) . -5187) ((marker . 1) . -5187) ((marker . 1) . -5230) ((marker . 1) . -5288) ((marker . 1) . -5293) ((marker . 1) . -5341) ((marker . 1) . -5369) ((marker . 1) . -5424) ((marker . 1) . -5444) ((marker . 1) . -5444) ((marker . 1) . -5612) ((marker . 1) . -5455) ((marker . 1) . -5475) ((marker . 1) . -5491) ((marker . 1) . -5521) ((marker . 1) . -5579) ((marker . 1) . -5616) ((marker . 1) . -5646) ((marker . 1) . -5647) ((marker . 1) . -5669) ((marker . 1) . -5693) ((marker . 1) . -5694) ((marker . 1) . -5698) ((marker . 1) . -5720) ((marker . 1) . -5720) ((marker . 1) . -5720) ((marker . 1) . -5732) ((marker . 1) . -5736) ((marker . 1) . -2988) ((marker . 1) . -3323) ((marker . 1) . -3329) ((marker . 1) . -3250) ((marker . 1) . -3348) ((marker . 1) . -3349) ((marker . 1) . -5611) ((marker . 1) . -6586) ((marker . 1) . -6586) ((marker . 1) . -2657) ((marker . 1) . -5773) ((marker . 1) . -5808) ((marker . 1) . -5808) ((marker . 1) . -5811) ((marker . 1) . -5819) ((marker . 1) . -5826) ((marker . 1) . -5876) ((marker . 1) . -5899) ((marker . 1) . -5941) ((marker . 1) . -6040) ((marker . 1) . -6040) ((marker . 1) . -6152) ((marker . 1) . -6152) ((marker . 1) . -6541) ((marker . 1) . -6576) ((marker . 1) . -6586) ((marker . 1) . -6588) ((marker . 1) . -228) ((marker . 1) . -6040) ((marker . 1) . -6040) ((marker . 1) . -6069) ((marker . 1) . -6098) ((marker . 996) . -5477) ((marker . 1802) . -6098) ((marker . 1802) . -6098) ((marker . 1) . -1796) ((marker . 1) . -2758) ((marker . 1) . -2758) (t 24171 19684 613388 283000) nil (6052 . 6070) nil ("discovert" . -6052) ((marker . 1802) . -9) 6061 nil (6058 . 6061) nil (6041 . 6058) nil ("g" . -6041) ((marker . 1802) . -1) 6042 nil (6041 . 6042) nil ("discoverer_" . -6041) ((marker . 1) . -11) ((marker . 1) . -11) ((marker . 1802) . -11) ((marker . 1) . -11) 6052 nil ("stream_" . -6052) ((marker . 1) . -7) ((marker . 1) . -7) ((marker . 1802) . -7) ((marker . 1) . -7) 6059 nil ("uri_" . -6059) ((marker . 1802) . -4) ((marker . 1) . -4) 6063 nil ("async" . -6063) ((marker . 1802) . -5) ((marker . 1) . -5) 6068 (t 24171 19490 138019 404000) nil ("
" . 6585) ("    " . -6585) ((marker . 1802) . -4) 6589 nil (6583 . 6584) nil (6575 . 6583) nil (6570 . 6575) ("    " . 6570) ((marker . 1802) . -4) 6574 nil (6569 . 6574) nil (6568 . 6569) nil (6558 . 6567) nil ("dta." . -6558) ((marker . 1802) . -4) 6562 nil ("l" . -6562) ((marker . 1802) . -1) 6563 nil (6558 . 6563) nil ("dta." . -6558) ((marker . 1802) . -4) 6562 nil (6558 . 6562) nil (6557 . 6559) ("(" . -6557) (6557 . 6558) nil (6550 . 6557) nil (6540 . 6550) nil (6535 . 6540) nil (6534 . 6535) nil (6518 . 6533) nil (6517 . 6519) ("(" . -6517) (6517 . 6518) nil (6506 . 6517) nil (6503 . 6506) nil (6498 . 6503) nil ("m" . -6498) ((marker . 1802) . -1) ("g" . -6499) ((marker . 1802) . -1) 6500 nil (6498 . 6500) nil (6481 . 6495) nil (6478 . 6484) nil (6473 . 6478) ("    " . 6473) ((marker . 1802) . -4) 6477 nil (6472 . 6477) nil (6471 . 6472) nil (6457 . 6470) nil (6455 . 6457) nil (6454 . 6456) ("(" . -6454) (6454 . 6455) nil (6435 . 6454) nil (6430 . 6435) nil (6412 . 6427) nil (6401 . 6412) nil (6398 . 6404) nil (6393 . 6398) ("    " . 6393) ((marker . 1802) . -4) 6397 nil (6392 . 6397) nil (6391 . 6392) nil (6381 . 6390) nil (6380 . 6382) ("(" . -6380) (6380 . 6381) nil (6370 . 6380) nil (6365 . 6370) nil (6360 . 6365) nil (6359 . 6360) nil (6353 . 6358) ("false" . 6353) nil (6352 . 6358) nil (6351 . 6352) nil (6347 . 6351) ("null" . 6347) nil (6347 . 6351) nil ("nll" . -6347) ((marker . 1802) . -3) 6350 nil (6347 . 6350) nil (6346 . 6348) ("(" . -6346) (6346 . 6347) nil (6333 . 6346) nil (6319 . 6333) nil (6314 . 6319) nil (6306 . 6311) nil (6285 . 6306) nil (6282 . 6285) nil (" " . -6282) ((marker . 1802) . -1) 6283 nil (6280 . 6283) nil (6279 . 6280) nil (6278 . 6279) nil (6257 . 6278) nil ("loo" . -6257) ((marker . 1802) . -3) 6260 nil (6252 . 6260) nil ("ma" . -6252) ((marker . 1802) . -2) 6254 nil ("i" . -6254) ((marker . 1802) . -1) 6255 nil (6236 . 6255) nil (6233 . 6239) nil (6228 . 6233) ("    " . 6228) ((marker . 1802) . -4) 6232 nil (6227 . 6232) nil (6220 . 6221) nil (6217 . 6219) nil (6216 . 6218) ("(" . -6216) (6216 . 6217) nil (6211 . 6216) nil (6202 . 6211) nil (6201 . 6202) nil (6198 . 6200) nil (6185 . 6198) nil ("\"" . -6185) ((marker . 1802) . -1) ("\"" . 6186) nil ("dat" . -6186) ((marker . 1802) . -3) 6189 nil (6186 . 6189) (6185 . 6187) ("\"" . -6185) (6185 . 6186) ("\"" . -6185) (6185 . 6186) nil (6184 . 6186) ("(" . -6184) (6184 . 6185) nil (6170 . 6184) nil (6161 . 6170) nil (6160 . 6161) nil (6155 . 6159) nil (6154 . 6155) nil (6151 . 6153) nil (6074 . 6084) nil ("discover" . -6074) ((marker . 1802) . -8) 6082 nil (6149 . 6150) ("\"" . -6149) (6149 . 6150) ("\"" . -6149) (6145 . 6150) nil ("\"" . -6145) ((marker . 1802) . -1) ("5" . -6146) ((marker . 1802) . -1) ("s" . -6147) ((marker . 1802) . -1) 6148 nil (6146 . 6148) ("\"" . -6145) (6145 . 6146) ("\"" . -6145) (6133 . 6146) nil (6113 . 6133) (6112 . 6114) ("\"" . -6112) (6112 . 6113) ("\"" . -6112) (6112 . 6113) nil (6111 . 6113) ("(" . -6111) (6111 . 6112) nil (6104 . 6111) nil ("print" . -6104) ((marker . 1802) . -5) 6109 nil (6104 . 6109) nil (6096 . 6104) (6095 . 6101) nil (6090 . 6094) ("        " . 6090) ((marker . 1802) . -8) (6098 . 6100) ("{" . -6098) (6098 . 6099) nil (6089 . 6098) nil (6083 . 6087) nil (6082 . 6083) nil (6069 . 6082) nil (6068 . 6070) ("(" . -6068) (6068 . 6069) nil (6059 . 6068) nil ("info_" . -6059) ((marker . 1802) . -5) ((marker . 1) . -5) 6064 nil ("get_" . -6064) ((marker . 1802) . -4) ((marker . 1) . -4) 6068 nil ("tags" . -6068) ((marker . 1802) . -4) ((marker . 1) . -4) 6072 nil (6037 . 6072) ("gst_disco" . -6037) ((marker . 1802) . -9) 6046 nil (6036 . 6046) nil (6035 . 6037) ("(" . -6035) (6035 . 6036) nil (6032 . 6035) nil (6027 . 6032) nil (6019 . 6024) nil ("l" . -6019) ((marker . 1802) . -1) 6020 nil (6012 . 6020) nil ("commdan" . -6012) ((marker . 1802) . -7) 6019 nil (6016 . 6019) nil (5995 . 6016) nil (5979 . 5995) nil (5958 . 5979) nil (5945 . 5958) nil (5942 . 5948) nil (5937 . 5942) ("    " . 5937) ((marker . 1802) . -4) 5941 nil (5936 . 5941) nil (5935 . 5936) nil (5923 . 5934) nil ("-" . -5923) ((marker . 1802) . -1) ("." . -5924) ((marker . 1802) . -1) 5925 nil ("di" . -5925) ((marker . 1802) . -2) 5927 nil (5919 . 5927) nil (5918 . 5920) ("(" . -5918) (5918 . 5919) nil (5898 . 5918) nil (5893 . 5898) nil (5821 . 5822) nil ("d" . -5821) ((marker . 1802) . -1) 5822 nil (5877 . 5889) nil ("i" . -5877) ((marker . 1802) . -1) 5878 nil (5872 . 5878) nil ("nothe" . -5872) ((marker . 1802) . -5) 5877 nil (5872 . 5877) nil (5871 . 5873) ("(" . -5871) (5871 . 5872) nil (5863 . 5871) nil (5842 . 5863) nil (5839 . 5845) nil (5834 . 5839) ("    " . 5834) ((marker . 1802) . -4) 5838 nil (5833 . 5838) nil (5832 . 5833) nil (5827 . 5831) nil (5825 . 5827) nil (5824 . 5825) nil (5812 . 5823) nil ("discovered_" . -5812) ((marker . 1802) . -11) ((marker . 1) . -11) 5823 nil ("cb" . -5823) ((marker . 1802) . -2) ((marker . 1) . -2) 5825 nil (5809 . 5825) ("on_dis" . -5809) ((marker . 1802) . -6) ((marker . 1) . -5) 5815 nil (5809 . 5815) nil ("0" . -5809) ((marker . 1802) . -1) ((marker . 1) . -1) 5810 nil (5809 . 5810) nil (5808 . 5810) ("(" . -5808) (5808 . 5809) nil (5799 . 5808) ("_callback" . 5799) nil (5798 . 5799) ("g" . 5798) nil (5797 . 5808) nil (5796 . 5797) nil (5787 . 5795) (5786 . 5788) ("\"" . -5786) (5786 . 5787) ("\"" . -5786) (5785 . 5787) nil (5784 . 5785) nil (5780 . 5784) nil (5769 . 5780) nil (5768 . 5770) ("(" . -5768) (5768 . 5769) nil (5752 . 5768) nil (5747 . 5752) nil ("
" . 5748) ("    ndis" . -5748) ((marker . 3676) . -4) ((marker . 1) . -4) ((marker . 1) . -4) ((marker . 1) . -4) ((marker . 1802) . -8) ((marker . 1802) . -8) 5756 nil (5752 . 5756) nil (5747 . 5752) (t 24171 18523 399361 267000) nil (3349 . 3350) (t 24171 18521 590411 128000) nil (3344 . 3349) nil (3335 . 3344) nil (3334 . 3335) nil (3251 . 3258) nil ("Busy" . -3251) ((marker . 1802) . -4) 3255 nil (3323 . 3329) (3322 . 3324) ("\"" . -3322) (3322 . 3323) ("\"" . -3322) (3322 . 3323) nil (3321 . 3323) ("(" . -3321) (3321 . 3322) nil (3314 . 3321) nil (3305 . 3314) nil (3276 . 3280) ("        " . 3276) (3308 . 3309) nil (3303 . 3308) ("_busy" . 3303) nil (3292 . 3303) ("_discoverer" . 3292) nil (3289 . 3292) ("gst" . 3289) nil (3304 . 3308) nil ("bysy" . -3304) ((marker . 1802) . -4) 3308 nil (3305 . 3308) nil (3284 . 3305) nil (3275 . 3284) nil (5646 . 5662) nil ("on_" . -5646) ((marker . 1802) . -3) ((marker . 1) . -3) ((marker . 1) . -3) ((marker . 1) . -3) 5649 nil ("discovererd_" . -5649) ((marker . 1802) . -12) ((marker . 1) . -9) ((marker . 1) . -11) ((marker . 1) . -12) 5661 nil ("cd" . -5661) ((marker . 1802) . -2) 5663 nil (5666 . 5667) nil ("*" . -5666) ((marker . 1802) . -1) 5667 nil (5666 . 5667) nil ("7" . -5666) ((marker . 1802) . -1) 5667 nil (5672 . 5673) nil (5665 . 5671) nil (5664 . 5665) nil (5659 . 5663) nil undo-tree-canary))
