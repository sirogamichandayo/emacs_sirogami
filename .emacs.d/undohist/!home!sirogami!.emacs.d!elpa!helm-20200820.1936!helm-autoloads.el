
((digest . "fe2e0730b9db0f3f2e9ffb4bd4105cab") (undo-list (32648 . 32656) (32623 . 32631) (32553 . 32561) (32463 . 32632) ("
;;;### (autoloads nil nil (\"helm-config.el\" \"helm-easymenu.el\" \"helm-global-bindings.el\"
;;;;;;  \"helm-pkg.el\" \"helm-types.el\" \"helm-x-files.el\") (24383 11693
;;;;;;  19787 794000))

;;;***
" . -32463) (32455 . 32463) (31904 . 31947) (31886 . 31894) (31814 . 31896) (32314 . 32322) (32294 . 32295) (31814 . 32313) ("
;;;### (autoloads nil \"helm-utils\" \"helm-utils.el\" (24383 11690 293695
;;;;;;  765000))
;;; Generated autoloads from helm-utils.el

(defvar helm-popup-tip-mode nil \"\\
Non-nil if Helm-Popup-Tip mode is enabled.
See the `helm-popup-tip-mode' command
for a description of this minor mode.
Setting this variable directly does not take effect;
either customize it (see the info node `Easy Customization')
or call the function `helm-popup-tip-mode'.\")

(custom-autoload 'helm-popup-tip-mode \"helm-utils\" nil)

(autoload 'helm-popup-tip-mode \"helm-utils\" \"\\
Show help-echo informations in a popup tip at end of line.

\\(fn &optional ARG)\" t nil)

;;;***
" . -31814) (31806 . 31814) (31264 . 31306) (31246 . 31254) (31178 . 31256) (31670 . 31678) (31657 . 31658) (31178 . 31669) ("
;;;### (autoloads nil \"helm-tags\" \"helm-tags.el\" (24383 11691 150356
;;;;;;  594000))
;;; Generated autoloads from helm-tags.el

(autoload 'helm-etags-select \"helm-tags\" \"\\
Preconfigured helm for etags.
If called with a prefix argument REINIT
or if any of the tag files have been modified, reinitialize cache.

This function aggregates three sources of tag files:

  1) An automatically located file in the parent directories,
     by `helm-etags-get-tag-file'.
  2) `tags-file-name', which is commonly set by `find-tag' command.
  3) `tags-table-list' which is commonly set by `visit-tags-table' command.

\\(fn REINIT)\" t nil)

;;;***
" . -31178) (31170 . 31178) (30357 . 30398) (30339 . 30347) (30271 . 30349) (31035 . 31043) (31029 . 31030) (30947 . 31034) (30941 . 30942) (30842 . 30946) (30836 . 30837) (30754 . 30841) (30734 . 30735) (30271 . 30753) ("
;;;### (autoloads nil \"helm-sys\" \"helm-sys.el\" (24383 11692 679527
;;;;;;  994000))
;;; Generated autoloads from helm-sys.el

(defvar helm-top-poll-mode nil \"\\
Non-nil if Helm-Top-Poll mode is enabled.
See the `helm-top-poll-mode' command
for a description of this minor mode.
Setting this variable directly does not take effect;
either customize it (see the info node `Easy Customization')
or call the function `helm-top-poll-mode'.\")

(custom-autoload 'helm-top-poll-mode \"helm-sys\" nil)

(autoload 'helm-top-poll-mode \"helm-sys\" \"\\
Refresh automatically helm top buffer once enabled.

\\(fn &optional ARG)\" t nil)

(autoload 'helm-top \"helm-sys\" \"\\
Preconfigured `helm' for top command.

\\(fn)\" t nil)

(autoload 'helm-list-emacs-process \"helm-sys\" \"\\
Preconfigured `helm' for Emacs process.

\\(fn)\" t nil)

(autoload 'helm-xrandr-set \"helm-sys\" \"\\
Preconfigured helm for xrandr.

\\(fn)\" t nil)

;;;***
" . -30271) (30263 . 30271) (30106 . 30149) (30089 . 30097) (30017 . 30098) (30017 . 30131) ("
;;;### (autoloads nil \"helm-shell\" \"helm-shell.el\" (24383 11690 117559
;;;;;;  764000))
;;; Generated autoloads from helm-shell.el

(defalias 'helm-shell-prompts 'helm-comint-prompts)

(defalias 'helm-shell-prompts-all 'helm-comint-prompts-all)

;;;***
" . -30017) (30009 . 30017) (29423 . 29469) (29399 . 29407) (29328 . 29415) (29860 . 29868) (29850 . 29851) (29488 . 29859) (29478 . 29479) (29328 . 29487) ("
;;;### (autoloads nil \"helm-semantic\" \"helm-semantic.el\" (24383 11690
;;;;;;  345735 947000))
;;; Generated autoloads from helm-semantic.el

(autoload 'helm-semantic \"helm-semantic\" \"\\
Preconfigured `helm' for `semantic'.
If ARG is supplied, pre-select symbol at point instead of current.

\\(fn ARG)\" t nil)

(autoload 'helm-semantic-or-imenu \"helm-semantic\" \"\\
Preconfigured helm for `semantic' or `imenu'.
If ARG is supplied, pre-select symbol at point instead of current
semantic tag in scope.

If `semantic-mode' is active in the current buffer, then use
semantic for generating tags, otherwise fall back to `imenu'.
Fill in the symbol at point by default.

\\(fn ARG)\" t nil)

;;;***
" . -29328) (29320 . 29328) (28337 . 28379) (28319 . 28327) (28249 . 28329) (29182 . 29190) (29176 . 29177) (28925 . 29181) (28919 . 28920) (28714 . 28924) (28708 . 28709) (28616 . 28713) (28610 . 28611) (28469 . 28615) (28463 . 28464) (28348 . 28468) (28342 . 28343) (28249 . 28347) ("
;;;### (autoloads nil \"helm-ring\" \"helm-ring.el\" (24383 11692 759589
;;;;;;  137000))
;;; Generated autoloads from helm-ring.el

(autoload 'helm-mark-ring \"helm-ring\" \"\\
Preconfigured `helm' for `helm-source-mark-ring'.

\\(fn)\" t nil)

(autoload 'helm-global-mark-ring \"helm-ring\" \"\\
Preconfigured `helm' for `helm-source-global-mark-ring'.

\\(fn)\" t nil)

(autoload 'helm-all-mark-rings \"helm-ring\" \"\\
Preconfigured `helm' for `helm-source-global-mark-ring' and `helm-source-mark-ring'.

\\(fn)\" t nil)

(autoload 'helm-register \"helm-ring\" \"\\
Preconfigured `helm' for Emacs registers.

\\(fn)\" t nil)

(autoload 'helm-show-kill-ring \"helm-ring\" \"\\
Preconfigured `helm' for `kill-ring'.
It is drop-in replacement of `yank-pop'.

First call open the kill-ring browser, next calls move to next line.

\\(fn)\" t nil)

(autoload 'helm-execute-kmacro \"helm-ring\" \"\\
Preconfigured helm for keyboard macros.
Define your macros with `f3' and `f4'.
See (info \\\"(emacs) Keyboard Macros\\\") for detailed infos.
This command is useful when used with persistent action.

\\(fn)\" t nil)

;;;***
" . -28249) (28241 . 28249) (28037 . 28081) (28012 . 28020) (27945 . 28029) (28097 . 28105) (28091 . 28092) (27945 . 28096) ("
;;;### (autoloads nil \"helm-regexp\" \"helm-regexp.el\" (24383 11692
;;;;;;  63057 202000))
;;; Generated autoloads from helm-regexp.el

(autoload 'helm-regexp \"helm-regexp\" \"\\
Preconfigured helm to build regexps.
`query-replace-regexp' can be run from there against found regexp.

\\(fn)\" t nil)

;;;***
" . -27945) (27937 . 27945) (26544 . 26587) (26526 . 26534) (26454 . 26536) (27796 . 27804) (27790 . 27791) (27441 . 27795) (27435 . 27436) (27287 . 27440) (27281 . 27282) (27169 . 27286) (27163 . 27164) (26454 . 27168) ("
;;;### (autoloads nil \"helm-occur\" \"helm-occur.el\" (24383 11691 38270
;;;;;;  525000))
;;; Generated autoloads from helm-occur.el

(autoload 'helm-occur \"helm-occur\" \"\\
Preconfigured helm for searching lines matching pattern in `current-buffer'.

When `helm-source-occur' is member of
`helm-sources-using-default-as-input' which is the default,
symbol at point is searched at startup.

When a region is marked search only in this region by narrowing.

To search in multiples buffers start from one of the commands listing
buffers (i.e. a helm command using `helm-source-buffers-list' like
`helm-mini') and use the multi occur buffers action.

This is the helm implementation that collect lines matching pattern
like vanilla Emacs `occur' but have nothing to do with it, the search
engine beeing completely different and also much faster.

\\(fn)\" t nil)

(autoload 'helm-occur-visible-buffers \"helm-occur\" \"\\
Run helm-occur on all visible buffers in frame.

\\(fn)\" t nil)

(autoload 'helm-occur-from-isearch \"helm-occur\" \"\\
Invoke `helm-occur' from isearch.

To use this bind it to a key in `isearch-mode-map'.

\\(fn)\" t nil)

(autoload 'helm-multi-occur-from-isearch \"helm-occur\" \"\\
Invoke `helm-multi-occur' from isearch.

With a prefix arg, reverse the behavior of
`helm-moccur-always-search-in-current'.
The prefix arg can be set before calling
`helm-multi-occur-from-isearch' or during the buffer selection.

To use this bind it to a key in `isearch-mode-map'.

\\(fn)\" t nil)

;;;***
" . -26454) (26446 . 26454) (25062 . 25103) (25044 . 25052) (24976 . 25054) (26311 . 26319) (26305 . 26306) (26190 . 26310) (26169 . 26170) (26062 . 26189) (26035 . 26036) (25949 . 26061) (25922 . 25923) (25828 . 25948) (25801 . 25802) (25715 . 25827) (25688 . 25689) (25589 . 25714) (25562 . 25563) (25281 . 25588) (25254 . 25255) (24976 . 25280) ("
;;;### (autoloads nil \"helm-net\" \"helm-net.el\" (24383 11689 801314
;;;;;;  711000))
;;; Generated autoloads from helm-net.el

(autoload 'helm-browse-url-firefox \"helm-net\" \"\\
Same as `browse-url-firefox' but detach from Emacs.

So when you quit Emacs you can keep your Firefox session open and
not be prompted to kill the Firefox process.

NOTE: Probably not supported on some systems (e.g., Windows).

\\(fn URL &optional IGNORE)\" t nil)

(autoload 'helm-browse-url-opera \"helm-net\" \"\\
Browse URL with Opera browser and detach from Emacs.

So when you quit Emacs you can keep your Opera session open and
not be prompted to kill the Opera process.

NOTE: Probably not supported on some systems (e.g., Windows).

\\(fn URL &optional IGNORE)\" t nil)

(autoload 'helm-browse-url-chromium \"helm-net\" \"\\
Browse URL with Google Chrome browser.

\\(fn URL &optional IGNORE)\" t nil)

(autoload 'helm-browse-url-uzbl \"helm-net\" \"\\
Browse URL with uzbl browser.

\\(fn URL &optional IGNORE)\" t nil)

(autoload 'helm-browse-url-conkeror \"helm-net\" \"\\
Browse URL with conkeror browser.

\\(fn URL &optional IGNORE)\" t nil)

(autoload 'helm-browse-url-next \"helm-net\" \"\\
Browse URL with next browser.

\\(fn URL &optional IGNORE)\" t nil)

(autoload 'helm-surfraw \"helm-net\" \"\\
Preconfigured `helm' to search PATTERN with search ENGINE.

\\(fn PATTERN ENGINE)\" t nil)

(autoload 'helm-google-suggest \"helm-net\" \"\\
Preconfigured `helm' for Google search with Google suggest.

\\(fn)\" t nil)

;;;***
" . -24976) (24968 . 24976) (17811 . 17853) (17793 . 17801) (17724 . 17803) (24831 . 24839) (24811 . 24812) (23761 . 24830) (23270 . 23271) (22044 . 23760) (21340 . 21341) (17724 . 22043) ("
;;;### (autoloads nil \"helm-mode\" \"helm-mode.el\" (24383 11692 247197
;;;;;;  827000))
;;; Generated autoloads from helm-mode.el

(autoload 'helm-comp-read \"helm-mode\" \"\\
Read a string in the minibuffer, with helm completion.

It is helm `completing-read' equivalent.

- PROMPT is the prompt name to use.

- COLLECTION can be a list, vector, obarray or hash-table.
  It can be also a function that receives three arguments:
  the values string, predicate and t. See `all-completions' for more details.

Keys description:

- TEST: A predicate called with one arg i.e candidate.

- INITIAL-INPUT: Same as input arg in `helm'.

- PRESELECT: See preselect arg of `helm'.

- DEFAULT: This option is used only for compatibility with regular
  Emacs `completing-read' (Same as DEFAULT arg of `completing-read').

- BUFFER: Name of helm-buffer.

- MUST-MATCH: Candidate selected must be one of COLLECTION.

- FUZZY: Enable fuzzy matching.

- REVERSE-HISTORY: When non--nil display history source after current
  source completion.

- REQUIRES-PATTERN: Same as helm attribute, default is 0.

- HISTORY: A list containing specific history, default is nil.
  When it is non--nil, all elements of HISTORY are displayed in
  a special source before COLLECTION.

- INPUT-HISTORY: A symbol. The minibuffer input history will be
  stored there, if nil or not provided, `minibuffer-history'
  will be used instead.

- CASE-FOLD: Same as `helm-case-fold-search'.

- DEL-INPUT: Boolean, when non--nil (default) remove the partial
  minibuffer input from HISTORY is present.

- PERSISTENT-ACTION: A function called with one arg i.e candidate.

- PERSISTENT-HELP: A string to document PERSISTENT-ACTION.

- MODE-LINE: A string or list to display in mode line.
  Default is `helm-comp-read-mode-line'.

- KEYMAP: A keymap to use in this `helm-comp-read'.
  (the keymap will be shared with history source)

- NAME: The name related to this local source.

- HEADER-NAME: A function to alter NAME, see `helm'.

- EXEC-WHEN-ONLY-ONE: Bound `helm-execute-action-at-once-if-one'
  to non--nil. (possibles values are t or nil).

- VOLATILE: Use volatile attribute.

- SORT: A predicate to give to `sort' e.g `string-lessp'
  Use this only on small data as it is inefficient.
  If you want to sort faster add a sort function to
  FC-TRANSFORMER.
  Note that FUZZY when enabled is already providing a sort function.

- FC-TRANSFORMER: A `filtered-candidate-transformer' function
  or a list of functions.

- HIST-FC-TRANSFORMER: A `filtered-candidate-transformer'
  function for the history source.

- MARKED-CANDIDATES: If non--nil return candidate or marked candidates as a list.

- NOMARK: When non--nil don't allow marking candidates.

- ALISTP: (default is non--nil) See `helm-comp-read-get-candidates'.

- CANDIDATES-IN-BUFFER: when non--nil use a source build with
  `helm-source-in-buffer' which is much faster.
  Argument VOLATILE have no effect when CANDIDATES-IN-BUFFER is non--nil.

- MATCH-PART: Allow matching only one part of candidate.
  See match-part documentation in `helm-source'.

- MATCH-DYNAMIC: See match-dynamic in `helm-source-sync'
  It has no effect when used with CANDIDATES-IN-BUFFER.

- ALLOW-NEST: Allow nesting this `helm-comp-read' in a helm session.
  See `helm'.

- MULTILINE: See multiline in `helm-source'.

- COERCE: See coerce in `helm-source'.

- GROUP: See group in `helm-source'.

Any prefix args passed during `helm-comp-read' invocation will be recorded
in `helm-current-prefix-arg', otherwise if prefix args were given before
`helm-comp-read' invocation, the value of `current-prefix-arg' will be used.
That means you can pass prefix args before or after calling a command
that use `helm-comp-read'.  See `helm-M-x' for example.

\\(fn PROMPT COLLECTION &key TEST INITIAL-INPUT DEFAULT PRESELECT (BUFFER \\\"*Helm Completions*\\\") MUST-MATCH FUZZY REVERSE-HISTORY (REQUIRES-PATTERN 0) HISTORY INPUT-HISTORY (CASE-FOLD helm-comp-read-case-fold-search) (DEL-INPUT t) (PERSISTENT-ACTION nil) (PERSISTENT-HELP \\\"DoNothing\\\") (MODE-LINE helm-comp-read-mode-line) HELP-MESSAGE (KEYMAP helm-comp-read-map) (NAME \\\"Helm Completions\\\") HEADER-NAME CANDIDATES-IN-BUFFER MATCH-PART MATCH-DYNAMIC EXEC-WHEN-ONLY-ONE QUIT-WHEN-NO-CAND (VOLATILE t) SORT FC-TRANSFORMER HIST-FC-TRANSFORMER (MARKED-CANDIDATES helm-comp-read-use-marked) NOMARK (ALISTP t) (CANDIDATE-NUMBER-LIMIT helm-candidate-number-limit) MULTILINE ALLOW-NEST COERCE (GROUP \\\\='helm))\" nil nil)

(autoload 'helm-read-file-name \"helm-mode\" \"\\
Read a file name with helm completion.
It is helm `read-file-name' emulation.

Argument PROMPT is the default prompt to use.

Keys description:

- NAME: Source name, default to \\\"Read File Name\\\".

- INITIAL-INPUT: Where to start reading file name, default to `default-directory'.

- BUFFER: `helm-buffer' name, defaults to \\\"*Helm Completions*\\\".

- TEST: A predicate called with one arg 'candidate'.

- NORET: Allow disabling helm-ff-RET (have no effect if helm-ff-RET
                                      isn't bound to RET).

- CASE-FOLD: Same as `helm-case-fold-search'.

- PRESELECT: helm preselection.

- HISTORY: Display HISTORY in a special source.

- MUST-MATCH: Can be 'confirm, nil, or t.

- FUZZY: Enable fuzzy matching when non-nil (Enabled by default).

- MARKED-CANDIDATES: When non--nil return a list of marked candidates.

- NOMARK: When non--nil don't allow marking candidates.

- ALISTP: Don't use `all-completions' in history (take effect only on history).

- PERSISTENT-ACTION-IF: a persistent if action function.

- PERSISTENT-HELP: persistent help message.

- MODE-LINE: A mode line message, default is `helm-read-file-name-mode-line-string'.

\\(fn PROMPT &key (NAME \\\"Read File Name\\\") (INITIAL-INPUT default-directory) (BUFFER \\\"*Helm file completions*\\\") TEST NORET (CASE-FOLD helm-file-name-case-fold-search) PRESELECT HISTORY MUST-MATCH (FUZZY t) DEFAULT MARKED-CANDIDATES (CANDIDATE-NUMBER-LIMIT helm-ff-candidate-number-limit) NOMARK (ALISTP t) (PERSISTENT-ACTION-IF \\\\='helm-find-files-persistent-action-if) (PERSISTENT-HELP \\\"Hit1 Expand Candidate, Hit2 or (C-u) Find file\\\") (MODE-LINE helm-read-file-name-mode-line-string))\" nil nil)

(defvar helm-mode nil \"\\
Non-nil if Helm mode is enabled.
See the `helm-mode' command
for a description of this minor mode.
Setting this variable directly does not take effect;
either customize it (see the info node `Easy Customization')
or call the function `helm-mode'.\")

(custom-autoload 'helm-mode \"helm-mode\" nil)

(autoload 'helm-mode \"helm-mode\" \"\\
Toggle generic helm completion.

All functions in Emacs that use `completing-read',
`read-file-name', `completion-in-region' and friends will use helm
interface when this mode is turned on.

However you can modify this behavior for functions of your choice
with `helm-completing-read-handlers-alist'.

Called with a positive arg, turn on unconditionally, with a
negative arg turn off.
You can toggle it with M-x `helm-mode'.

About `ido-mode':
DO NOT enable `ido-everywhere' when using `helm-mode'.  Instead of
using `ido-mode', add the commands where you want to use ido to
`helm-completing-read-handlers-alist' with `ido' as value.

Note: This mode is incompatible with Emacs23.

\\(fn &optional ARG)\" t nil)

;;;***
" . -17724) (17716 . 17724) (16464 . 16506) (16446 . 16454) (16376 . 16456) (17578 . 17586) (17572 . 17573) (17450 . 17577) (17430 . 17431) (16986 . 17449) (16980 . 16981) (16873 . 16985) (16867 . 16868) (16768 . 16872) (16762 . 16763) (16650 . 16767) (16644 . 16645) (16531 . 16649) (16525 . 16526) (16376 . 16530) ("
;;;### (autoloads nil \"helm-misc\" \"helm-misc.el\" (24383 11691 490617
;;;;;;  874000))
;;; Generated autoloads from helm-misc.el

(autoload 'helm-world-time \"helm-misc\" \"\\
Preconfigured `helm' to show world time.
Default action change TZ environment variable locally to emacs.

\\(fn)\" t nil)

(autoload 'helm-insert-latex-math \"helm-misc\" \"\\
Preconfigured helm for latex math symbols completion.

\\(fn)\" t nil)

(autoload 'helm-ratpoison-commands \"helm-misc\" \"\\
Preconfigured `helm' to execute ratpoison commands.

\\(fn)\" t nil)

(autoload 'helm-stumpwm-commands \"helm-misc\" \"\\
Preconfigured helm for stumpwm commands.

\\(fn)\" t nil)

(autoload 'helm-minibuffer-history \"helm-misc\" \"\\
Preconfigured `helm' for `minibuffer-history'.

\\(fn)\" t nil)

(defvar helm-epa-mode nil \"\\
Non-nil if Helm-Epa mode is enabled.
See the `helm-epa-mode' command
for a description of this minor mode.
Setting this variable directly does not take effect;
either customize it (see the info node `Easy Customization')
or call the function `helm-epa-mode'.\")

(custom-autoload 'helm-epa-mode \"helm-misc\" nil)

(autoload 'helm-epa-mode \"helm-misc\" \"\\
Enable helm completion on gpg keys in epa functions.

\\(fn &optional ARG)\" t nil)

(autoload 'helm-epa-list-keys \"helm-misc\" \"\\
List all gpg keys.
This is the helm interface for `epa-list-keys'.

\\(fn)\" t nil)

;;;***
" . -16376) (16368 . 16376) (16179 . 16220) (16161 . 16169) (16093 . 16171) (16233 . 16241) (16223 . 16224) (16093 . 16232) ("
;;;### (autoloads nil \"helm-man\" \"helm-man.el\" (24383 11692 955738
;;;;;;  934000))
;;; Generated autoloads from helm-man.el

(autoload 'helm-man-woman \"helm-man\" \"\\
Preconfigured `helm' for Man and Woman pages.
With a prefix arg reinitialize the cache.

\\(fn ARG)\" t nil)

;;;***
" . -16093) (16085 . 16093) (15346 . 15390) (15321 . 15329) (15254 . 15338) (15941 . 15949) (15931 . 15932) (15432 . 15940) (15419 . 15420) (15254 . 15431) ("
;;;### (autoloads nil \"helm-locate\" \"helm-locate.el\" (24383 11692
;;;;;;  823638 50000))
;;; Generated autoloads from helm-locate.el

(autoload 'helm-projects-find-files \"helm-locate\" \"\\
Find files with locate in `helm-locate-project-list'.
With a prefix arg refresh the database in each project.

\\(fn UPDATE)\" t nil)

(autoload 'helm-locate \"helm-locate\" \"\\
Preconfigured `helm' for Locate.
Note: you can add locate options after entering pattern.
See 'man locate' for valid options and also `helm-locate-command'.

You can specify a local database with prefix argument ARG.
With two prefix arg, refresh the current local db or create it if
it doesn't exists.

To create a user specific db, use
\\\"updatedb -l 0 -o db_path -U directory\\\".
Where db_path is a filename matched by
`helm-locate-db-file-regexp'.

\\(fn ARG)\" t nil)

;;;***
" . -15254) (15246 . 15254) (14508 . 14550) (14490 . 14498) (14420 . 14500) (15108 . 15116) (15102 . 15103) (14997 . 15107) (14973 . 14974) (14420 . 14996) ("
;;;### (autoloads nil \"helm-info\" \"helm-info.el\" (24383 11691 734805
;;;;;;  381000))
;;; Generated autoloads from helm-info.el

(autoload 'helm-info \"helm-info\" \"\\
Preconfigured `helm' for searching Info files' indices.

With a prefix argument \\\\[universal-argument], set REFRESH to
non-nil.

Optional parameter REFRESH, when non-nil, re-evaluates
`helm-default-info-index-list'.  If the variable has been
customized, set it to its saved value.  If not, set it to its
standard value. See `custom-reevaluate-setting' for more.

REFRESH is useful when new Info files are installed.  If
`helm-default-info-index-list' has not been customized, the new
Info files are made available.

\\(fn &optional REFRESH)\" t nil)

(autoload 'helm-info-at-point \"helm-info\" \"\\
Preconfigured `helm' for searching info at point.

\\(fn)\" t nil)

;;;***
" . -14420) (14412 . 14420) (13975 . 14018) (13957 . 13965) (13885 . 13967) (14271 . 14279) (14265 . 14266) (13965 . 14270) (13959 . 13960) (13885 . 13964) ("
;;;### (autoloads nil \"helm-imenu\" \"helm-imenu.el\" (24383 11690 982227
;;;;;;  404000))
;;; Generated autoloads from helm-imenu.el

(autoload 'helm-imenu \"helm-imenu\" \"\\
Preconfigured `helm' for `imenu'.

\\(fn)\" t nil)

(autoload 'helm-imenu-in-all-buffers \"helm-imenu\" \"\\
Preconfigured `helm' for fetching imenu entries in all buffers with similar mode as current.
A mode is similar as current if it is the same, it is derived
i.e. `derived-mode-p' or it have an association in
`helm-imenu-all-buffer-assoc'.

\\(fn)\" t nil)

;;;***
" . -13885) (13877 . 13885) (13535 . 13581) (13510 . 13518) (13439 . 13527) (13727 . 13735) (13721 . 13722) (13439 . 13726) ("
;;;### (autoloads nil \"helm-id-utils\" \"helm-id-utils.el\" (24383 11691
;;;;;;  550663 982000))
;;; Generated autoloads from helm-id-utils.el

(autoload 'helm-gid \"helm-id-utils\" \"\\
Preconfigured `helm' for `gid' command line of `ID-Utils'.
Need A database created with the command `mkid' above
`default-directory'.
Need id-utils as dependency which provide `mkid', `gid' etc..
See <https://www.gnu.org/software/idutils/>.

\\(fn)\" t nil)

;;;***
" . -13439) (13431 . 13439) (12339 . 12381) (12321 . 12329) (12251 . 12331) (12450 . 13301) (12444 . 12445) (12251 . 12449) ("
;;;### (autoloads nil \"helm-help\" \"helm-help.el\" (24383 11690 445813
;;;;;;  221000))
;;; Generated autoloads from helm-help.el

(autoload 'helm-documentation \"helm-help\" \"\\
Preconfigured `helm' for Helm documentation.
With a prefix arg refresh the documentation.

Find here the documentation of all documented sources.

\\(fn)\" t nil)

(defvar helm-comp-read-mode-line \"\\\\<helm-comp-read-map>C/\\\\[helm-cr-empty-string]:Empty \\\\<helm-map>\\\\[helm-help]:Help \\\\[helm-select-action]:Act \\\\[helm-maybe-exit-minibuffer]/f1/f2/f-n:NthAct \\\\[helm-toggle-suspend-update]:Tog.suspend \\\\[helm-customize-group]:Conf\")

(defvar helm-read-file-name-mode-line-string \"\\\\<helm-read-file-map>\\\\[helm-help]:Help C/\\\\[helm-cr-empty-string]:Empty \\\\<helm-map>\\\\[helm-select-action]:Act \\\\[helm-maybe-exit-minibuffer]/f1/f2/f-n:NthAct \\\\[helm-toggle-suspend-update]:Tog.suspend \\\\[helm-customize-group]:Conf\" \"\\
String displayed in mode-line in `helm-source-find-files'.\")

(defvar helm-top-mode-line \"\\\\<helm-top-map>\\\\[helm-help]:Help \\\\<helm-map>\\\\[helm-select-action]:Act \\\\[helm-maybe-exit-minibuffer]/f1/f2/f-n:NthAct \\\\[helm-toggle-suspend-update]:Tog.suspend \\\\[helm-customize-group]:Conf\")

;;;***
" . -12251) (12243 . 12251) (11601 . 11643) (11583 . 11591) (11513 . 11593) (12105 . 12113) (12095 . 12096) (11925 . 12104) (11915 . 11916) (11730 . 11924) (11724 . 11725) (11620 . 11729) (11614 . 11615) (11513 . 11619) ("
;;;### (autoloads nil \"helm-grep\" \"helm-grep.el\" (24383 11690 750048
;;;;;;  131000))
;;; Generated autoloads from helm-grep.el

(autoload 'helm-goto-precedent-file \"helm-grep\" \"\\
Go to previous file in Helm grep/etags buffers.

\\(fn)\" t nil)

(autoload 'helm-goto-next-file \"helm-grep\" \"\\
Go to previous file in Helm grep/etags buffers.

\\(fn)\" t nil)

(autoload 'helm-do-grep-ag \"helm-grep\" \"\\
Preconfigured `helm' for grepping with AG in `default-directory'.
With prefix arg prompt for type if available with your AG
version.

\\(fn ARG)\" t nil)

(autoload 'helm-grep-do-git-grep \"helm-grep\" \"\\
Preconfigured `helm' for git-grepping `default-directory'.
With a prefix arg ARG git-grep the whole repository.

\\(fn ARG)\" t nil)

;;;***
" . -11513) (11505 . 11513) (10858 . 10905) (10829 . 10837) (10762 . 10850) (11354 . 11362) (11348 . 11349) (11258 . 11353) (11252 . 11253) (10916 . 11257) (10910 . 10911) (10762 . 10915) ("
;;;### (autoloads nil \"helm-for-files\" \"helm-for-files.el\" (24383
;;;;;;  11689 753277 412000))
;;; Generated autoloads from helm-for-files.el

(autoload 'helm-for-files \"helm-for-files\" \"\\
Preconfigured `helm' for opening files.
Run all sources defined in `helm-for-files-preferred-list'.

\\(fn)\" t nil)

(autoload 'helm-multi-files \"helm-for-files\" \"\\
Preconfigured helm like `helm-for-files' but running locate only on demand.

Allow toggling back and forth from locate to others sources with
`helm-multi-files-toggle-locate-binding' key.
This avoids launching locate needlessly when what you are
searching for is already found.

\\(fn)\" t nil)

(autoload 'helm-recentf \"helm-for-files\" \"\\
Preconfigured `helm' for `recentf'.

\\(fn)\" t nil)

;;;***
" . -10762) (10754 . 10762) (10472 . 10514) (10454 . 10462) (10384 . 10464) (10616 . 10624) (10606 . 10607) (10474 . 10615) (10468 . 10469) (10384 . 10473) ("
;;;### (autoloads nil \"helm-font\" \"helm-font.el\" (24383 11690 866137
;;;;;;  767000))
;;; Generated autoloads from helm-font.el

(autoload 'helm-select-xfont \"helm-font\" \"\\
Preconfigured `helm' to select Xfont.

\\(fn)\" t nil)

(autoload 'helm-ucs \"helm-font\" \"\\
Preconfigured `helm' for `ucs-names'.

Called with a prefix arg force reloading cache.

\\(fn ARG)\" t nil)

;;;***
" . -10384) (10376 . 10384) (9604 . 9646) (9586 . 9594) (9516 . 9596) (10238 . 10246) (10228 . 10229) (9516 . 10237) ("
;;;### (autoloads nil \"helm-find\" \"helm-find.el\" (24383 11692 183148
;;;;;;  914000))
;;; Generated autoloads from helm-find.el

(autoload 'helm-find \"helm-find\" \"\\
Preconfigured `helm' for the find shell command.

Recursively find files whose names are matched by all specified
globbing PATTERNs under the current directory using the external
program specified in `find-program' (usually \\\"find\\\").  Every
input PATTERN is silently wrapped into two stars: *PATTERN*.

With prefix argument, prompt for a directory to search.

When user option `helm-findutils-search-full-path' is non-nil,
match against complete paths, otherwise, against file names
without directory part.

The (possibly empty) list of globbing PATTERNs can be followed by
the separator \\\"*\\\" plus any number of additional arguments that
are passed to \\\"find\\\" literally.

\\(fn ARG)\" t nil)

;;;***
" . -9516) (9508 . 9516) (7167 . 7210) (7149 . 7157) (7077 . 7159) (9367 . 9375) (9361 . 9362) (9044 . 9366) (9034 . 9035) (8740 . 9043) (8730 . 8731) (8045 . 8739) (8035 . 8036) (7975 . 8044) (7955 . 7956) (7077 . 7974) ("
;;;### (autoloads nil \"helm-files\" \"helm-files.el\" (24383 11692 887686
;;;;;;  962000))
;;; Generated autoloads from helm-files.el

(defvar helm-ff-cache-mode nil \"\\
Non-nil if Helm-Ff-Cache mode is enabled.
See the `helm-ff-cache-mode' command
for a description of this minor mode.
Setting this variable directly does not take effect;
either customize it (see the info node `Easy Customization')
or call the function `helm-ff-cache-mode'.\")

(custom-autoload 'helm-ff-cache-mode \"helm-files\" nil)

(autoload 'helm-ff-cache-mode \"helm-files\" \"\\
Auto refresh `helm-find-files' cache when emacs is idle.

You will probably don't want to start this mode directly but instead
customize `helm-ff-keep-cached-candidates' to a non nil value to
enable it.
With `helm-ff-keep-cached-candidates' set to a nil value the mode will
disable itself.

When Emacs is idle, refresh the cache all the
`helm-ff-refresh-cache-delay' seconds then stop when done or after
`helm-ff-cache-mode-max-idle-time' if emacs is still idle.

\\(fn &optional ARG)\" t nil)

(autoload 'helm-projects-history \"helm-files\" \"\\


\\(fn ARG)\" t nil)

(autoload 'helm-browse-project \"helm-files\" \"\\
Preconfigured helm to browse projects.
Browse files and see status of project with its VCS.
Only HG and GIT are supported for now.
Fall back to `helm-browse-project-find-files' if current
directory is not under control of one of those VCS.
With a prefix ARG browse files recursively, with two prefix ARG
rebuild the cache.
If the current directory is found in the cache, start
`helm-browse-project-find-files' even with no prefix ARG.
NOTE: The prefix ARG have no effect on the VCS controlled
directories.

Needed dependencies for VCS:
<https://github.com/emacs-helm/helm-ls-git>
and
<https://github.com/emacs-helm/helm-ls-hg>.

\\(fn ARG)\" t nil)

(autoload 'helm-find-files \"helm-files\" \"\\
Preconfigured `helm' for helm implementation of `find-file'.
Called with a prefix arg show history if some.
Don't call it from programs, use `helm-find-files-1' instead.
This is the starting point for nearly all actions you can do on
files.

\\(fn ARG)\" t nil)

(autoload 'helm-delete-tramp-connection \"helm-files\" \"\\
Allow deleting tramp connection or marked tramp connections at once.

This replace `tramp-cleanup-connection' which is partially broken
in Emacs < to 25.1.50.1 (See Emacs Bug#24432).

It allows additionally to delete more than one connection at
once.

\\(fn)\" t nil)

;;;***
" . -7077) (7069 . 7077) (6751 . 6797) (6726 . 6734) (6655 . 6743) (6919 . 6927) (6905 . 6906) (6655 . 6918) ("
;;;### (autoloads nil \"helm-external\" \"helm-external.el\" (24383 11692
;;;;;;  359283 427000))
;;; Generated autoloads from helm-external.el

(autoload 'helm-run-external-command \"helm-external\" \"\\
Preconfigured `helm' to run External PROGRAM asyncronously from Emacs.
If program is already running exit with error.
You can set your own list of commands with
`helm-external-commands-list'.

\\(fn PROGRAM)\" t nil)

;;;***
" . -6655) (6647 . 6655) (6203 . 6245) (6185 . 6193) (6115 . 6195) (6509 . 6517) (6503 . 6504) (6385 . 6508) (6379 . 6380) (6232 . 6384) (6222 . 6223) (6115 . 6231) ("
;;;### (autoloads nil \"helm-eval\" \"helm-eval.el\" (24383 11689 304929
;;;;;;  290000))
;;; Generated autoloads from helm-eval.el

(autoload 'helm-eval-expression \"helm-eval\" \"\\
Preconfigured `helm' for `helm-source-evaluation-result'.

\\(fn ARG)\" t nil)

(autoload 'helm-eval-expression-with-eldoc \"helm-eval\" \"\\
Preconfigured `helm' for `helm-source-evaluation-result' with `eldoc' support.

\\(fn)\" t nil)

(autoload 'helm-calcul-expression \"helm-eval\" \"\\
Preconfigured `helm' for `helm-source-calculation-result'.

\\(fn)\" t nil)

;;;***
" . -6115) (6107 . 6115) (5571 . 5615) (5546 . 5554) (5479 . 5563) (5963 . 5971) (5957 . 5958) (5827 . 5962) (5821 . 5822) (5696 . 5826) (5690 . 5691) (5593 . 5695) (5587 . 5588) (5479 . 5592) ("
;;;### (autoloads nil \"helm-eshell\" \"helm-eshell.el\" (24383 11691
;;;;;;  674759 273000))
;;; Generated autoloads from helm-eshell.el

(autoload 'helm-esh-pcomplete \"helm-eshell\" \"\\
Preconfigured `helm' to provide Helm completion in Eshell.

\\(fn)\" t nil)

(autoload 'helm-eshell-history \"helm-eshell\" \"\\
Preconfigured Helm for Eshell history.

\\(fn)\" t nil)

(autoload 'helm-eshell-prompts \"helm-eshell\" \"\\
Pre-configured `helm' to browse the prompts of the current Eshell.

\\(fn)\" t nil)

(autoload 'helm-eshell-prompts-all \"helm-eshell\" \"\\
Pre-configured `helm' to browse the prompts of all Eshell sessions.

\\(fn)\" t nil)

;;;***
" . -5479) (5471 . 5479) (5019 . 5070) (4981 . 4989) (4913 . 5011) (5306 . 5314) (5296 . 5297) (5047 . 5305) (5037 . 5038) (4913 . 5046) ("
;;;### (autoloads nil \"helm-elisp-package\" \"helm-elisp-package.el\"
;;;;;;  (24383 11690 241655 583000))
;;; Generated autoloads from helm-elisp-package.el

(autoload 'helm-list-elisp-packages \"helm-elisp-package\" \"\\
Preconfigured `helm' for listing and handling Emacs packages.

\\(fn ARG)\" t nil)

(autoload 'helm-list-elisp-packages-no-fetch \"helm-elisp-package\" \"\\
Preconfigured Helm for Emacs packages.

Same as `helm-list-elisp-packages' but don't fetch packages on
remote.  Called with a prefix ARG always fetch packages on
remote.

\\(fn ARG)\" t nil)

;;;***
" . -4913) (4905 . 4913) (3604 . 3647) (3586 . 3594) (3514 . 3596) (4764 . 4772) (4758 . 4759) (4642 . 4763) (4636 . 4637) (4554 . 4641) (4548 . 4549) (4445 . 4553) (4439 . 4440) (4326 . 4444) (4312 . 4313) (4067 . 4325) (4061 . 4062) (3839 . 4066) (3833 . 3834) (3778 . 3838) (3756 . 3757) (3635 . 3777) (3629 . 3630) (3514 . 3634) ("
;;;### (autoloads nil \"helm-elisp\" \"helm-elisp.el\" (24383 11691 410556
;;;;;;  397000))
;;; Generated autoloads from helm-elisp.el

(autoload 'helm-lisp-completion-at-point \"helm-elisp\" \"\\
Preconfigured Helm for Lisp symbol completion at point.

\\(fn)\" t nil)

(autoload 'helm-complete-file-name-at-point \"helm-elisp\" \"\\
Preconfigured Helm to complete file name at point.

\\(fn &optional FORCE)\" t nil)

(autoload 'helm-lisp-indent \"helm-elisp\" \"\\


\\(fn)\" t nil)

(autoload 'helm-lisp-completion-or-file-name-at-point \"helm-elisp\" \"\\
Preconfigured Helm to complete Lisp symbol or filename at point.
Filename completion happens if string start after or between a
double quote.

\\(fn)\" t nil)

(autoload 'helm-apropos \"helm-elisp\" \"\\
Preconfigured Helm to describe commands, functions, variables and faces.
In non interactives calls DEFAULT argument should be provided as
a string, i.e. the `symbol-name' of any existing symbol.

\\(fn DEFAULT)\" t nil)

(autoload 'helm-manage-advice \"helm-elisp\" \"\\
Preconfigured `helm' to disable/enable function advices.

\\(fn)\" t nil)

(autoload 'helm-locate-library \"helm-elisp\" \"\\
Preconfigured helm to locate elisp libraries.

\\(fn)\" t nil)

(autoload 'helm-timers \"helm-elisp\" \"\\
Preconfigured `helm' for timers.

\\(fn)\" t nil)

(autoload 'helm-complex-command-history \"helm-elisp\" \"\\
Preconfigured `helm' for complex command history.

\\(fn)\" t nil)

;;;***
" . -3514) (3506 . 3514) (3357 . 3402) (3332 . 3340) (3263 . 3349) (3359 . 3367) (3353 . 3354) (3263 . 3358) ("
;;;### (autoloads nil \"helm-dabbrev\" \"helm-dabbrev.el\" (24383 11689
;;;;;;  853355 118000))
;;; Generated autoloads from helm-dabbrev.el

(autoload 'helm-dabbrev \"helm-dabbrev\" \"\\
Preconfigured helm for dynamic abbreviations.

\\(fn)\" t nil)

;;;***
" . -3263) (3255 . 3263) (2727 . 2772) (2702 . 2710) (2633 . 2719) (3108 . 3116) (3098 . 3099) (2633 . 3107) ("
;;;### (autoloads nil \"helm-command\" \"helm-command.el\" (24383 11691
;;;;;;  798854 563000))
;;; Generated autoloads from helm-command.el

(autoload 'helm-M-x \"helm-command\" \"\\
Preconfigured `helm' for Emacs commands.
It is `helm' replacement of regular `M-x'
`execute-extended-command'.

Unlike regular `M-x' Emacs vanilla `execute-extended-command'
command, the prefix args if needed, can be passed AFTER starting
`helm-M-x'.  When a prefix arg is passed BEFORE starting
`helm-M-x', the first `C-u' while in `helm-M-x' session will
disable it.

You can get help on each command by persistent action.

\\(fn ARG)\" t nil)

;;;***
" . -2633) (2625 . 2633) (2174 . 2218) (2149 . 2157) (2082 . 2166) (2481 . 2489) (2475 . 2476) (2348 . 2480) (2342 . 2343) (2212 . 2347) (2206 . 2207) (2082 . 2211) ("
;;;### (autoloads nil \"helm-comint\" \"helm-comint.el\" (24383 11690
;;;;;;  926184 131000))
;;; Generated autoloads from helm-comint.el

(autoload 'helm-comint-prompts \"helm-comint\" \"\\
Pre-configured `helm' to browse the prompts of the current comint buffer.

\\(fn)\" t nil)

(autoload 'helm-comint-prompts-all \"helm-comint\" \"\\
Pre-configured `helm' to browse the prompts of all comint sessions.

\\(fn)\" t nil)

(autoload 'helm-comint-input-ring \"helm-comint\" \"\\
Preconfigured `helm' that provide completion of `comint' history.

\\(fn)\" t nil)

;;;***
" . -2082) (2074 . 2082) (1944 . 1987) (1926 . 1934) (1854 . 1936) (1933 . 1941) (1927 . 1928) (1854 . 1932) ("
;;;### (autoloads nil \"helm-color\" \"helm-color.el\" (24383 11693 87839
;;;;;;  483000))
;;; Generated autoloads from helm-color.el

(autoload 'helm-colors \"helm-color\" \"\\
Preconfigured `helm' for color.

\\(fn)\" t nil)

;;;***
" . -1854) (1846 . 1854) (1584 . 1629) (1559 . 1567) (1490 . 1576) (1699 . 1707) (1693 . 1694) (1583 . 1698) (1577 . 1578) (1490 . 1582) ("
;;;### (autoloads nil \"helm-buffers\" \"helm-buffers.el\" (24383 11692
;;;;;;  423332 340000))
;;; Generated autoloads from helm-buffers.el

(autoload 'helm-buffers-list \"helm-buffers\" \"\\
Preconfigured `helm' to list buffers.

\\(fn)\" t nil)

(autoload 'helm-mini \"helm-buffers\" \"\\
Preconfigured `helm' displaying `helm-mini-default-sources'.

\\(fn)\" t nil)

;;;***
" . -1490) (1482 . 1490) (1089 . 1135) (1065 . 1073) (994 . 1081) (1333 . 1341) (1327 . 1328) (1083 . 1332) (1077 . 1078) (994 . 1082) ("
;;;### (autoloads nil \"helm-bookmark\" \"helm-bookmark.el\" (24383 11690
;;;;;;  393773 38000))
;;; Generated autoloads from helm-bookmark.el

(autoload 'helm-bookmarks \"helm-bookmark\" \"\\
Preconfigured `helm' for bookmarks.

\\(fn)\" t nil)

(autoload 'helm-filtered-bookmarks \"helm-bookmark\" \"\\
Preconfigured `helm' for bookmarks (filtered by category).
Optional source `helm-source-bookmark-addressbook' is loaded only
if external addressbook-bookmark package is installed.

\\(fn)\" t nil)

;;;***
" . -994) (986 . 994) (258 . 304) (238 . 246) (167 . 250) (841 . 849) (835 . 836) (648 . 840) (628 . 629) (167 . 647) ("
;;;### (autoloads nil \"helm-adaptive\" \"helm-adaptive.el\" (24383 11690
;;;;;;  497853 402000))
;;; Generated autoloads from helm-adaptive.el

(defvar helm-adaptive-mode nil \"\\
Non-nil if Helm-Adaptive mode is enabled.
See the `helm-adaptive-mode' command
for a description of this minor mode.
Setting this variable directly does not take effect;
either customize it (see the info node `Easy Customization')
or call the function `helm-adaptive-mode'.\")

(custom-autoload 'helm-adaptive-mode \"helm-adaptive\" nil)

(autoload 'helm-adaptive-mode \"helm-adaptive\" \"\\
Toggle adaptive sorting in all sources.

\\(fn &optional ARG)\" t nil)

(autoload 'helm-reset-adaptive-history \"helm-adaptive\" \"\\
Delete all `helm-adaptive-history' and his file.
Useful when you have a old or corrupted
`helm-adaptive-history-file'.

\\(fn)\" t nil)

;;;***
" . -167) (t 24383 11693 952496 249000) (32655 . 32663) (32631 . 32639) (32561 . 32569) (32463 . 32639) (31912 . 31955) (31894 . 31902) (31822 . 31904) (32322 . 32330) (32302 . 32303) (31814 . 32321) (31272 . 31314) (31254 . 31262) (31184 . 31264) (31676 . 31684) (31663 . 31664) (31176 . 31675) (30363 . 30404) (30345 . 30353) (30277 . 30355) (31041 . 31049) (31035 . 31036) (30953 . 31040) (30947 . 30948) (30848 . 30952) (30842 . 30843) (30760 . 30847) (30740 . 30741) (30269 . 30759) (30112 . 30155) (30094 . 30102) (30022 . 30104) (30014 . 30136) (29428 . 29474) (29403 . 29411) (29332 . 29420) (29864 . 29872) (29854 . 29855) (29492 . 29863) (29482 . 29483) (29324 . 29491) (28341 . 28383) (28323 . 28331) (28253 . 28333) (29186 . 29194) (29180 . 29181) (28929 . 29185) (28923 . 28924) (28718 . 28928) (28712 . 28713) (28620 . 28717) (28614 . 28615) (28473 . 28619) (28467 . 28468) (28352 . 28472) (28346 . 28347) (28245 . 28351) (28041 . 28085) (28017 . 28025) (27950 . 28033) (28102 . 28110) (28096 . 28097) (27942 . 28101) (26549 . 26592) (26531 . 26539) (26460 . 26541) (27802 . 27810) (27796 . 27797) (27447 . 27801) (27441 . 27442) (27293 . 27446) (27287 . 27288) (27175 . 27292) (27169 . 27170) (26452 . 27174) (25068 . 25109) (25050 . 25058) (24982 . 25060) (26317 . 26325) (26311 . 26312) (26196 . 26316) (26175 . 26176) (26068 . 26195) (26041 . 26042) (25955 . 26067) (25928 . 25929) (25834 . 25954) (25807 . 25808) (25721 . 25833) (25694 . 25695) (25595 . 25720) (25568 . 25569) (25287 . 25594) (25260 . 25261) (24974 . 25286) (17817 . 17859) (17799 . 17807) (17729 . 17809) (24836 . 24844) (24816 . 24817) (23766 . 24835) (23275 . 23276) (22049 . 23765) (21345 . 21346) (17721 . 22048) (16469 . 16511) (16451 . 16459) (16381 . 16461) (17583 . 17591) (17577 . 17578) (17455 . 17582) (17435 . 17436) (16991 . 17454) (16985 . 16986) (16878 . 16990) (16872 . 16873) (16773 . 16877) (16767 . 16768) (16655 . 16772) (16649 . 16650) (16536 . 16654) (16530 . 16531) (16373 . 16535) (16184 . 16225) (16166 . 16174) (16098 . 16176) (16238 . 16246) (16228 . 16229) (16090 . 16237) (15351 . 15395) (15327 . 15335) (15260 . 15343) (15947 . 15955) (15937 . 15938) (15438 . 15946) (15425 . 15426) (15252 . 15437) (14514 . 14556) (14496 . 14504) (14426 . 14506) (15114 . 15122) (15108 . 15109) (15003 . 15113) (14979 . 14980) (14418 . 15002) (13981 . 14024) (13963 . 13971) (13891 . 13973) (14277 . 14285) (14271 . 14272) (13971 . 14276) (13965 . 13966) (13883 . 13970) (13541 . 13587) (13516 . 13524) (13445 . 13533) (13733 . 13741) (13727 . 13728) (13437 . 13732) (12345 . 12387) (12327 . 12335) (12257 . 12337) (12456 . 13307) (12450 . 12451) (12249 . 12455) (11607 . 11649) (11589 . 11597) (11519 . 11599) (12111 . 12119) (12101 . 12102) (11931 . 12110) (11921 . 11922) (11736 . 11930) (11730 . 11731) (11626 . 11735) (11620 . 11621) (11511 . 11625) (10864 . 10911) (10833 . 10841) (10766 . 10856) (11358 . 11366) (11352 . 11353) (11262 . 11357) (11256 . 11257) (10920 . 11261) (10914 . 10915) (10758 . 10919) (10476 . 10518) (10458 . 10466) (10388 . 10468) (10620 . 10628) (10610 . 10611) (10478 . 10619) (10472 . 10473) (10380 . 10477) (9608 . 9650) (9590 . 9598) (9520 . 9600) (10242 . 10250) (10232 . 10233) (9512 . 10241) (7171 . 7214) (7153 . 7161) (7081 . 7163) (9371 . 9379) (9365 . 9366) (9048 . 9370) (9038 . 9039) (8744 . 9047) (8734 . 8735) (8049 . 8743) (8039 . 8040) (7979 . 8048) (7959 . 7960) (7073 . 7978) (6755 . 6801) (6730 . 6738) (6659 . 6747) (6923 . 6931) (6909 . 6910) (6651 . 6922) (6207 . 6249) (6189 . 6197) (6119 . 6199) (6513 . 6521) (6507 . 6508) (6389 . 6512) (6383 . 6384) (6236 . 6388) (6226 . 6227) (6111 . 6235) (5575 . 5619) (5550 . 5558) (5483 . 5567) (5967 . 5975) (5961 . 5962) (5831 . 5966) (5825 . 5826) (5700 . 5830) (5694 . 5695) (5597 . 5699) (5591 . 5592) (5483 . 5596) (4909 . 4917) (3608 . 3651) (3590 . 3598) (3518 . 3600) (4768 . 4776) (4762 . 4763) (4646 . 4767) (4640 . 4641) (4558 . 4645) (4552 . 4553) (4449 . 4557) (4443 . 4444) (4330 . 4448) (4316 . 4317) (4071 . 4329) (4065 . 4066) (3843 . 4070) (3837 . 3838) (3782 . 3842) (3760 . 3761) (3639 . 3781) (3633 . 3634) (3518 . 3638) (4076 . 4084) (3624 . 3675) (3586 . 3594) (3518 . 3616) (3911 . 3919) (3901 . 3902) (3652 . 3910) (3642 . 3643) (3510 . 3651) (3361 . 3406) (3336 . 3344) (3267 . 3353) (3363 . 3371) (3357 . 3358) (3259 . 3362) (2731 . 2776) (2706 . 2714) (2637 . 2723) (3112 . 3120) (3102 . 3103) (2629 . 3111) (2178 . 2222) (2153 . 2161) (2086 . 2170) (2485 . 2493) (2479 . 2480) (2352 . 2484) (2346 . 2347) (2216 . 2351) (2210 . 2211) (2078 . 2215) (1948 . 1991) (1930 . 1938) (1859 . 1940) (1938 . 1946) (1932 . 1933) (1851 . 1937) (1589 . 1634) (1564 . 1572) (1495 . 1581) (1704 . 1712) (1698 . 1699) (1588 . 1703) (1582 . 1583) (1487 . 1587) (1094 . 1140) (1070 . 1078) (999 . 1086) (1338 . 1346) (1332 . 1333) (1088 . 1337) (1082 . 1083) (991 . 1087) (263 . 309) (238 . 246) (167 . 255) (841 . 849) (835 . 836) (648 . 840) (628 . 629) (167 . 647) (t 24383 11693 368052 324000)))
