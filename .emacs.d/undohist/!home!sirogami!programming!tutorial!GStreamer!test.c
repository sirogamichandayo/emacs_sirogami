
((digest . "975a12ea544723d10a0caeb2c111cf98") (undo-list nil ("    }
" . 1997) ((marker . 3050) . -6) ((marker . 3050) . -6) ((marker) . -6) nil ("      }
" . 1997) ((marker . 2026) . -8) ((marker . 2026) . -8) ((marker) . -8) nil ("    if (msg != NULL) {
" . 1962) ((marker . 3050) . -23) ((marker . 3050) . -23) ((marker . 1962) . -23) ((marker) . -23) nil ("    /* Parse message */
" . 1962) ((marker . 1997) . -24) ((marker . 1997) . -24) ((marker) . -24) nil ("        }
" . 2044) ((marker . 3050) . -10) ((marker . 3050) . -10) ((marker) . -10) nil ("          data.seek_done = TRUE;
" . 2044) ((marker . 2050) . -33) ((marker . 2050) . -33) ((marker) . -33) nil ("              GST_SEEK_FLAG_FLUSH | GST_SEEK_FLAG_KEY_UNIT, 30 * GST_SECOND);
" . 2044) ((marker . 1997) . -22) ((marker . 3050) . -78) ((marker . 3050) . -78) ((marker) . -78) nil ("          gst_element_seek_simple (data.pipeline, GST_FORMAT_TIME,
" . 2044) ((marker . 2050) . -67) ((marker . 2050) . -67) ((marker) . -67) nil ("          g_print (\"\\nReached 10s, performing seek...\\n\");
" . 2044) ((marker . 3050) . -59) ((marker . 3050) . -59) ((marker) . -59) nil ("        if (data.seek_enabled && !data.seek_done && current > 10 * GST_SECOND) {
" . 2044) ((marker . 2050) . -81) ((marker . 2050) . -81) ((marker) . -81) nil ("        /* If seeking is enabled, we have not done it yet, and the time is right, seek */
" . 2044) ((marker . 3050) . -90) ((marker . 3050) . -90) ((marker) . -90) nil ("
" . 2044) ((marker . 2050) . -1) ((marker . 2050) . -1) ((marker) . -1) nil ("            GST_TIME_ARGS (current), GST_TIME_ARGS (data.duration));
" . 2044) ((marker . 3050) . -69) ((marker . 3050) . -69) ((marker) . -69) nil ("        g_print (\"Position %\" GST_TIME_FORMAT \" / %\" GST_TIME_FORMAT \"\\r\",
" . 2044) ((marker . 2050) . -75) ((marker . 2050) . -75) ((marker) . -75) nil ("        /* Print current position and total duration */
" . 2044) ((marker . 3050) . -56) ((marker . 3050) . -56) ((marker) . -56) nil ("
" . 2044) ((marker . 2050) . -1) ((marker . 2050) . -1) ((marker) . -1) nil ("        }
" . 2044) ((marker . 3050) . -10) ((marker . 3050) . -10) ((marker) . -10) nil ("          }
" . 2044) ((marker . 1997) . -11) ((marker . 2050) . -12) ((marker . 2050) . -12) ((marker) . -12) nil ("            g_printerr (\"Could not query current duration.\\n\");
" . 2044) ((marker . 3050) . -64) ((marker . 3050) . -64) ((marker) . -64) nil ("          if (!gst_element_query_duration (data.pipeline, GST_FORMAT_TIME, &data.duration)) {
" . 2044) ((marker . 2050) . -94) ((marker . 2050) . -94) ((marker) . -94) nil ("        if (!GST_CLOCK_TIME_IS_VALID (data.duration)) {
" . 2044) ((marker . 3050) . -56) ((marker . 3050) . -56) ((marker) . -56) nil ("        /* If we didn't know it yet, query the stream duration */
" . 2044) ((marker . 1997) . -61) ((marker . 2050) . -66) ((marker . 2050) . -66) ((marker) . -66) nil ("
" . 2044) ((marker . 3050) . -1) ((marker . 3050) . -1) ((marker) . -1) nil ("        }
" . 2044) ((marker . 2050) . -10) ((marker . 2050) . -10) ((marker) . -10) nil ("          g_printerr (\"Could not query current position.\\n\");
" . 2044) ((marker . 3050) . -62) ((marker . 3050) . -62) ((marker . 1997) . -62) ((marker) . -62) nil ("        if (!gst_element_query_position (data.pipeline, GST_FORMAT_TIME, &current)) {
" . 2044) ((marker . 2050) . -86) ((marker . 2050) . -86) nil ("        /* Query the current position of the stream */
" . 2044) ((marker . 1997) . -22) ((marker . 3050) . -55) ((marker . 3050) . -55) nil ("
" . 2044) ((marker . 2050) . -1) ((marker . 2050) . -1) nil ("        gint64 current = -1;
" . 2044) ((marker . 3050) . -29) ((marker . 3050) . -29) nil ("      if (data.playing) {
" . 2044) ((marker . 1997) . -22) ((marker . 1997) . -22) ((marker . 2050) . -26) ((marker . 2050) . -26) nil ("      /* We got no message, this means the timeout expired */
" . 2044) ((marker . 1997) . -22) ((marker . 3050) . -62) ((marker . 3050) . -62) nil ("else {
" . 2044) ((marker . 2050) . -7) ((marker . 2050) . -7) ("    } " . -2044) ((marker . 1997) . -6) ((marker . 1997) . -6) 2050 nil undo-tree-canary))
