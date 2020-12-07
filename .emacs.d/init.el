;; test

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; base
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; add elisp, conf, public_repos direcotyr in load-path
(defun add-to-load-path (&rest paths)
  (let (path)
    (dolist (path paths paths)
      (let ((default-directory
	      (expand-file-name (concat user-emacs-directory path))))
	(add-to-list 'load-path default-directory)
	(if (fboundp 'normal-top-level-add-subdirs-to-load-path)
	    (normal-top-level-add-subdirs-to-load-path))))))
;; call function
(add-to-load-path "elisp" "conf" "public_repos")

;; custom-file to "custom.el"
(setq custom-file (locate-user-emacs-file "custom.el"))
;; if custom-file not exist, create it.
(unless (file-exists-p custom-file)
  (write-region "" nil custom-file))
;; read custom-file
(load custom-file)

;; enable package.el
;; add Marmalade, MELPA to package repository
(require 'package)
(add-to-list
 'package-archives
 '("marmalade" . "https://marmalade-repo.org/packages/"))
(add-to-list
 'package-archives
 '("melpa" . "https://melpa.org/packages/"))
(package-initialize)

;; use init-loader.el
(require 'init-loader)
(init-loader-load "~/.emacs.d/conf")

;; Change directory backup file to ~/.emacs.d/backups/
(add-to-list 'backup-directory-alist
             (cons "." "~/.emacs.d/backups/"))
;; Change directory autosave file to ~/.emacs.d/backup/
(setq auto-save-file-name-transforms
      `((".*" ,(expand-file-name "~/.emacs.d/backups/") t)))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; aslias
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; fack C-x C-c
(defalias 'exit 'save-buffers-kill-emacs)
(global-unset-key (kbd "C-x C-c"))

;; buffer copy
;; (global-set-key (kbd "C-c C-y") (lambda()
;; 								  (interactive)
;; 								  (kbd "C-x h")
;; 								  (kbd "M-w")))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; keybinding
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; backspace -> "C-h"
(define-key key-translation-map (kbd "C-h") (kbd "<DEL>"))
;; forward-word -> "C-." / backward-word -> "C-,"
(define-key global-map (kbd "C-.") 'forward-word)
(define-key global-map (kbd "C-,") 'backward-word)
;; backward-kill-word -> "M-u"
(define-key global-map (kbd "C-u") 'backward-kill-word)
;; kill-whole-line -> "C-k"
(define-key global-map (kbd "C-k") 'kill-whole-line)
;; forward-list -> "M-." / backward-word -> "M-,"
(define-key global-map (kbd "M-.") 'forward-list)
(define-key global-map (kbd "M-,") 'backward-list)

;;

(setq next-line-width 3)
(setq previous-line-width 3)
(define-key global-map (kbd "C-c C-n") (lambda()
                                     (interactive)
                                     (next-line next-line-width)))
(define-key global-map (kbd "C-c C-p") (lambda()
                                     (interactive)
                                     (previous-line previous-line-width)))
;; forward-sentence -> "M-n" / backward-sentence -> "M-p"
(define-key global-map (kbd "M-n") 'forward-paragraph)
(define-key global-map (kbd "M-p") 'backward-paragraph)
;; new-and-indent -> "C-m"
(define-key global-map (kbd "C-m") 'newline-and-indent)
;; toggle-truncate-lines -> "C-c l"
(setq truncate-lines t)
(define-key global-map (kbd "C-c l") 'toggle-truncate-lines)
;; transpose-chars -> "C-t"
(define-key global-map (kbd "C-t") 'other-window)
;; eval-buffer -> "C-c C-e"
(define-key global-map (kbd "C-c C-e") 'eval-buffer)
;; upcase-previous-word -> "M-u"
(define-key global-map (kbd "M-u") (lambda()
                                     (interactive)
                                     (upcase-word 1)
                                   ))

;;;;;;;;;;
;; move line
(defun move-line-down ()
  (interactive)
  (let ((col (current-column)))
    (save-excursion
      (forward-line)
      (transpose-lines 1))
    (forward-line)
    (move-to-column col)))

(defun move-line-up ()
  (interactive)
  (let ((col (current-column)))
    (save-excursion
      (forward-line)
      (transpose-lines -1)
      )
    (forward-line -1)
    (move-to-column col)))

;; move region space
(defun move-region-down ()
  (interactive)
  (let ((col (current-column)))
    (kill-region (region-beginning) (region-end))
    (forward-line 1)
    (yank)
    (set-mark  (region-beginning) (region-end))
    (move-to-column col)))

(defun move-region-up ()
  (interactive)
  (let ((col (current-column)))
    (kill-region (region-beginning) (region-end))
    (forward-line -1)
    (yank)
    (set-mark (region-beginning) (region-end))
    (move-to-column col)))

;; keybinding move line and region
;; (require 'mykie)
;; (mykie:set-keys nil
;;   "C-<up>" 
;;   :default     move-line-up
;;   :region      move-region-up
;;   "C-<down>"
;;   :default     move-line-down
;;   :region      move-region-down
;;   )

;; duplicate thing
(require 'duplicate-thing)
(define-key global-map (kbd "M-z") 'duplicate-thing)

;; recenter3
;; I hate moving to the bottom and top of recenter-top-bottom(C-l).
;; Replace recenter-top-bottom to recenter3
(setq recenter3-width-rate 4.0)
(setq recenter3-positions '(center1 center2 center3))
(defun recenter3 (&optional arg)
  (interactive "P")
  (cond
   (arg (recenter arg))                        ; Always respect ARG.
   (t
    (setq recenter3-last-op
          (if (eq this-command last-command)
              (car (or (cdr (member recenter3-last-op recenter3-positions))
                       recenter3-positions))
            (car recenter3-positions)))
    (let ((this-scroll-margin
           (min (max 0 scroll-margin)
                (truncate (/ (window-body-height) 4.0))))
          (recenter3-width (truncate (/ (window-body-height) recenter3-width-rate))))
      (cond ((eq recenter3-last-op 'center2)
             (recenter))
            ((eq recenter3-last-op 'center1)
             (recenter (+ this-scroll-margin recenter3-width)))
            ((eq recenter3-last-op 'center3)
             (recenter (- (- (- (window-body-height) 1) this-scroll-margin) recenter3-width)))
            ((integerp recenter3-last-op)
             (recenter recenter3-last-op))
            ((floatp recenter3-last-op)
             (recenter (round (* recenter3-last-op (window-height))))))))))
(define-key global-map (kbd "C-l") 'recenter3)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; mode line
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; no display column number on mode line
(line-number-mode 0)

;; display file size
(size-indication-mode t)

;; display clock
(setq display-time-day-and-date t)
(setq display-time-24hr-format t)
(display-time-mode t)

;; dispaly battery
(display-battery-mode t)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; title bar
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; display file path on title bar
(setq frame-title-format "%f")

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; fringe
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; display colum number
(global-linum-mode t)

;; kill scroll bar
(scroll-bar-mode 0)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; tool bar
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; kill tool bar
(tool-bar-mode 0)
;; kill menu bar
(menu-bar-mode 0)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; window
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; window size
(define-key global-map (kbd "M-<up>") 'enlarge-window)
(define-key global-map (kbd "M-<down>") 'shrink-window)
(define-key global-map (kbd "M-<right>") 'enlarge-window-horizontally)
(define-key global-map (kbd "M-<left>") 'shrink-window-horizontally)

;; load theme
(load-theme 'heroku t)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; color
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; Current line get to highlight 
(defface my-hl-line-face
  ;; if background is dark
  '((((class color) (background dark))
     (:background "gray" t))
    ;; if background is light
    (((class color) (background light))
     (:background "LightSkyBlue" t))
    (t (:bold t)))
  "hl-hine's my face")
(setq hl-line-face 'my-hl-line-face)
(global-hl-line-mode 0)



;; color(base)
(set-face-foreground 'default "gray90")
(set-face-background 'default "gray30")
(set-face-foreground 'font-lock-comment-face "LightSalmon1")
(set-face-foreground 'font-lock-constant-face "PaleTurquoise1")
(set-face-foreground 'font-lock-preprocessor-face "cyan2")
(set-face-foreground 'font-lock-type-face "cyan2")
(set-face-foreground 'font-lock-keyword-face "khaki1")
(set-face-foreground 'font-lock-function-name-face "LightBlue3")
(set-face-foreground 'font-lock-string-face "SeaGreen3")

(setq hl-todo-keyword-faces
      '(("TODO"   . "#FF0000")
        ("FIXME"  . "#FF0000")
        ("DEBUG"  . "#FF0000")
        ("GOTCHA" . "#FF4500")
        ("STUB"   . "#1E90FF")))	  
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; font
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(set-face-attribute 'default nil :height 110)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; edit
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; width of TAB
(setq-default tab-width 4)

;; use tabs word
(setq-default indent-tabs-mode t)


;; display match branket
(setq show-paren-delay 0)
(show-paren-mode t)

;; on electric-pair-mode
(electric-pair-mode 1)

;;;;;;;;;;
;; c/c++ macro

(fset 'c-main
   "int main(int argc, char **argv\C-e\C-m{\C-m")
(fset 'indent-and-brackets
	  "\C-e\C-m{\C-m")
(fset 'c-include-angle-brackets
	  "#include <>\C-b")
(fset 'c-include-quort
	  "#include \"\"\C-b")
(fset 'c++-constexpr
	  "constexpr ")
(fset 'c-continue
	  "continue;\C-m")
(fset 'c-pretty-function
	  "__PRETTY_FUNCTION__ ")
(fset 'c++-pretty-function-and-std-output
	  "std::cout << __PRETTY_FUNCTION__ << std::endl;")
(fset 'c++-std-output
	  [?s ?t ?d ?: ?: ?c ?o ?u ?t ?  ?< ?< ?  ?< ?< ?\S-  ?s ?t ?d ?: ?: ?e ?n ?d ?l ?\; ?\C-, ?\C-, ?\C-b ?\C-b ?\C-b])
(fset 'c++-using-namespace-std
	  "using namespace std;\C-m")
(fset 'c-unsigned
	  "unsigned ")
(fset 'c++-unused-variable
	  "[[maybe_unused]] ")
(fset 'c-return
	  "return ")
(fset 'c++-static-cast
	  "static_cast<>()\C-b\C-b\C-b")
(fset 'c++-template
	  "template <>\C-b")
(fset 'c-else-if
	  "else if ()\C-b")
(fset 'c-branket
   [?\M-a tab ?\( ?\C-f ?\C-h ?\C-e ?\) ? ])
(fset 'compe-rep
	  "\C-eREP()\C-b")
(fset 'compe-for
	  "\C-efor()\C-b")
(fset 'compe-all
	  "ALL()\C-b")
(fset 'compe-debug
	  "DEBUG();\C-b\C-b")

(fset 'c++-vector-normal-1
	  "vector<>\C-b")
(fset 'c++-vector-normal-2
	  "vector<vector<>>\C-b\C-b")

(fset 'c++-vector-bool-1
	  "vector<bool> ")
(fset 'c++-vector-bool-2
	  "vector<vector<bool>> ")


(fset 'c++-vector-ll-1
	  "vector<ll> ")
(fset 'c++-vector-ll-2
	  "vector<vector<ll>> ")

(fset 'c++-vector-double-1
	  "vector<double> ")
(fset 'c++-vector-double-2
	  "vector<vector<double>> ")

(fset 'c++-vector-string-1
	  "vector<string> ")
(fset 'c++-vector-string-2
	  "vector<vector<string>> ")

(fset 'c++-vector-pair-ll-ll-1
	  "vector<pair<ll, ll>> ")
(fset 'c++-vector-pair-ll-ll-2
	  "vector<vector<pair<ll, ll>>> ")

(fset 'c++-stl-push-back
	  "\C-e.push_back()\C-b")
(fset 'c++-stl-pop-back
	  "\C-e.pop_back()\C-b")
(fset 'c++-stl-emplace-back
	  "\C-e.emplace_back()\C-b")

(fset 'c++-stl-push-front
	  "\C-e.push_front()\C-b")
(fset 'c++-stl-pop-front
	  "\C-e.pop_front()\C-b")
(fset 'c++-stl-emplace-front
	  "\C-e.emplace_front()\C-b")

(fset 'c++-pair-ll-ll
	  "pair<ll, ll> ")
(fset 'c++-pair-first
	  ".first")
(fset 'c++-pair-second
	  ".second")
(fset 'c++-std-output-res
	  "std::cout << res << std::endl;")
(fset 'c++-std-output-fixed
   "\C-ccoofixed << setprecision(10\C-f << ")
(fset 'c++-std-output-yes-no
	  "std::cout << (ok ? \"Yes\C-f : \"No\C-f\C-f << std::endl;")
(fset 'c++-comma-indent
	  "\C-e;\C-m")


(defalias 'compe-base
  (lambda()
	(interactive)
	(insert-file "~/.emacs.d/compe/base.cc")
	(goto-line 77)))
(defalias 'compe-dinic
  (lambda()
	(interactive)
	(insert-file "~/.emacs.d/compe/dinic.cc")))
(defalias 'compe-inverse-element
  (lambda()
	(interactive)
	(insert-file "~/.emacs.d/compe/inverse_element.cc")))
(defalias 'compe-crt
  (lambda()
	(interactive)
	(insert-file "~/.emacs.d/compe/chinese_remainder.cc")))
(defalias 'compe-bit
  (lambda()
	(interactive)
	(insert-file "~/.emacs.d/compe/bit.cc")))
(defalias 'compe-eratos
  (lambda()
	(interactive)
	(insert-file "~/.emacs.d/compe/eratos.cc")))
(defalias 'compe-min-max
  (lambda()
	(interactive)
	(insert-file "~/.emacs.d/compe/min_max.cc")))
(defalias 'compe-to-digit
  (lambda()
	(interactive)
	(insert-file "~/.emacs.d/compe/to_digit.cc")))
(defalias 'compe-union-find
  (lambda()
	(interactive)
	(insert-file "~/.emacs.d/compe/union_find.cc")))
(defalias 'compe-bipartite-matching
  (lambda()
	(interactive)
	(insert-file "~/.emacs.d/compe/bipartite_matching.cc")))
(defalias 'compe-dx4-dy4
  (lambda()
	(interactive)
	(insert-file "~/.emacs.d/compe/dy4_dy4.cc")))
(defalias 'compe-gcd-lcm
  (lambda()
	(interactive)
	(insert-file "~/.emacs.d/compe/gcd_lcm.cc")))
(defalias 'compe-modint
  (lambda()
	(interactive)
	(insert-file "~/.emacs.d/compe/modint.cc")))
(defalias 'compe-modpow
  (lambda()
	(interactive)
	(insert-file "~/.emacs.d/compe/modpow.cc")))
(defalias 'compe-to-divisor
  (lambda()
	(interactive)
	(insert-file "~/.emacs.d/compe/to_divisor.cc")))
(defalias 'compe-seg-tree
  (lambda()
	(interactive)
	(insert-file "~/.emacs.d/compe/seg_tree.cc")))
(defalias 'compe-seg-tree-weight
  (lambda()
	(interactive)
	(insert-file "~/.emacs.d/compe/seg_tree_weight.cc")))
(defalias 'compe-prime-factor
  (lambda()
	(interactive)
	(insert-file "~/.emacs.d/compe/prime_factor.cc")))
(defalias 'compe-combination
  (lambda()
	(interactive)
	(insert-file "~/.emacs.d/compe/combination.cc")))
(defalias 'compe-z-algorithm
  (lambda()
	(interactive)
	(insert-file "~/.emacs.d/compe/z_algorithm.cc")))
(defalias 'compe-make-vec
  (lambda()
	(interactive)
	(insert-file "~/.emacs.d/compe/make_vec.cc")))

;; c
(defun my-c-mode-hook ()
    (setq c-basic-offset 4)
    (c-set-offset 'substatement-open 0)
    (define-key c-mode-map (kbd "C-c m") 'c-main)
    (define-key c-mode-map (kbd "C-c [") 'indent-and-brackets)
	(define-key c-mode-map (kbd "C-c i") 'c-include)
    
    (define-key c-mode-map (kbd "C-c C-n") (lambda()
                                               (interactive)
                                               (next-line next-line-width)))
    (define-key c-mode-map (kbd "C-c C-p") (lambda()
                                               (interactive)
                                               (previous-line previous-line-width))))
(add-hook 'c-mode-hook 'my-c-mode-hook)

;; c++
(defun my-c++-mode-hook ()
  (setq c-basic-offset 4)
  (c-set-offset 'substatement-open 0)
  (define-key c++-mode-map (kbd "C-c c [") 'indent-and-brackets)
  (define-key c++-mode-map (kbd "C-c c 9") 'c-branket)
  (define-key c++-mode-map (kbd "C-c c 0") 'c-branket)
  
  (define-key c++-mode-map (kbd "C-c c i q") 'c-include-quort)
  (define-key c++-mode-map (kbd "C-c c i ,") 'c-include-angle-brackets)
  
  (define-key c++-mode-map (kbd "C-c c e") 'c-else-if)
  
  (define-key c++-mode-map (kbd "C-c c c s") 'c++-constexpr)
  
  (define-key c++-mode-map (kbd "C-c c c o") 'c-continue)
  
  (define-key c++-mode-map (kbd "C-c c p f") 'c-pretty-function)
  
  (define-key c++-mode-map (kbd "C-c c p f") 'c++-pair-first)
  (define-key c++-mode-map (kbd "C-c c p s") 'c++-pair-second)
  (define-key c++-mode-map (kbd "C-c c p l") 'c++-pair-ll-ll)
  
  (define-key c++-mode-map (kbd "C-c c o p") 'c++-pretty-function-and-std-output)
  (define-key c++-mode-map (kbd "C-c c o o") 'c++-std-output)
  (define-key c++-mode-map (kbd "C-c c o r") 'c++-std-output-res)
  (define-key c++-mode-map (kbd "C-c c o f") 'c++-std-output-fixed)
  (define-key c++-mode-map (kbd "C-c c o y n") 'c++-std-output-yes-no)
  
  (define-key c++-mode-map (kbd "C-c c ;") 'c++-comma-indent)
  
  (define-key c++-mode-map (kbd "C-c c m") 'c-main)
  
  (define-key c++-mode-map (kbd "C-c c u s") 'c++-using-namespace-std)
  
  (define-key c++-mode-map (kbd "C-c c u n") 'c-unsigned)
  
  (define-key c++-mode-map (kbd "C-c c n v") 'c++-unused-variable)
  
;;  (define-key c++-mode-map (kbd "C-c c r") 'c-return)
  
;;  (define-key c++-mode-map (kbd "C-c c s t") 'c++-static)
  
  (define-key c++-mode-map (kbd "C-c c t") 'c++-template)

  (define-key c++-mode-map (kbd "C-c c r") 'compe-rep)
  (define-key c++-mode-map (kbd "C-c c f") 'compe-for)
  (define-key c++-mode-map (kbd "C-c c a") 'compe-all)
  (define-key c++-mode-map (kbd "C-c c d") 'compe-debug)

  (define-key c++-mode-map (kbd "C-c c l d 1") 'c++-vector-double-1)
  (define-key c++-mode-map (kbd "C-c c l d 2") 'c++-vector-double-2)
  
  (define-key c++-mode-map (kbd "C-c c l s 1") 'c++-vector-string-1)
  (define-key c++-mode-map (kbd "C-c c l s 2") 'c++-vector-string-2)
  
  (define-key c++-mode-map (kbd "C-c c l 1") 'c++-vector-ll-1)
  (define-key c++-mode-map (kbd "C-c c l 2") 'c++-vector-ll-2)
  
  (define-key c++-mode-map (kbd "C-c c l n 1") 'c++-vector-normal-1)
  (define-key c++-mode-map (kbd "C-c c l n 2") 'c++-vector-normal-2)
  
  (define-key c++-mode-map (kbd "C-c c l b 1") 'c++-vector-bool-1)
  (define-key c++-mode-map (kbd "C-c c l b 2") 'c++-vector-bool-2)
  
  (define-key c++-mode-map (kbd "C-c c l p l 1") 'c++-vector-pair-ll-ll-1)
  (define-key c++-mode-map (kbd "C-c c l p l 2") 'c++-vector-pair-ll-ll-2)

  ;; stl
  (define-key c++-mode-map (kbd "C-c c s p b") 'c++-stl-push-back)
  (define-key c++-mode-map (kbd "C-c c s o b") 'c++-stl-pop-back)
  (define-key c++-mode-map (kbd "C-c c s e b") 'c++-stl-emplace-back)
  
  (define-key c++-mode-map (kbd "C-c c s p f") 'c++-stl-push-front)
  (define-key c++-mode-map (kbd "C-c c s o f") 'c++-stl-pop-front)
  (define-key c++-mode-map (kbd "C-c c s e f") 'c++-stl-emplace-front)
  
  
  (define-key c++-mode-map (kbd "C-c c c c b") 'compe-base)
  
  
  (define-key c++-mode-map (kbd "C-c C-n") (lambda()
                                             (interactive)
                                             (next-line next-line-width)))
  (define-key c++-mode-map (kbd "C-c C-p") (lambda()
                                             (interactive)
                                             (previous-line previous-line-width)))

  (define-key c++-mode-map (kbd "C-M-n") 'c-end-of-defun)
  (define-key c++-mode-map (kbd "C-M-p") 'c-beginning-of-defun)
  
  (define-key c++-mode-map (kbd "C-a") 'c-beginning-of-statement)
  (define-key c++-mode-map (kbd "M-a") 'move-beginning-of-line)
  
  (add-to-list 'flycheck-clang-args "-I/home/sirogami/Downloads/boost_1_74_0/")
  
  (setq flycheck-clang-language-standard "c++17")
  (setq flycheck-gcc-language-standard "c++17"))

(add-hook 'c++-mode-hook 'my-c++-mode-hook)

;; gst mode
(defun my-gst-mode-hook ()
  (add-to-list 'flycheck-clang-include-path "/usr/include/glib-2.0" )
  (add-to-list 'flycheck-clang-include-path "/usr/lib/x86_64-linux-gnu/glib-2.0/include" )
  (add-to-list 'flycheck-clang-include-path "/usr/include/gstreamer-1.0")

  (add-to-list 'flycheck-clang-args "-pthread")
  (add-to-list 'flycheck-clang-args "-lgstreamer-1.0")
  (add-to-list 'flycheck-clang-args "-lgobject-2.0")
  (add-to-list 'flycheck-clang-args "-lglib-2.0")
  (add-to-list 'flycheck-clang-args "-lgstvideo-1.0")
  (add-to-list 'flycheck-clang-args "-lgstbase-1.0")
  )
(define-minor-mode gst-mode ()
  (interactive)
  ;;  :lighter " GST"
  )
(add-hook 'gst-mode-hook 'my-gst-mode-hook)

;; gtk mode
(defun my-gtk-mode-hook ()
  (add-to-list 'flycheck-clang-include-path "/usr/include/gtk-3.0")
  (add-to-list 'flycheck-clang-include-path "/usr/include/gio-unix-2.0")
  (add-to-list 'flycheck-clang-include-path "/usr/include/cairo")
  (add-to-list 'flycheck-clang-include-path "/usr/include/pango-1.0")
  (add-to-list 'flycheck-clang-include-path "/usr/include/harfbuzz")
  (add-to-list 'flycheck-clang-include-path "/usr/include/pango-1.0")
  (add-to-list 'flycheck-clang-include-path "/usr/include/atk-1.0")
  (add-to-list 'flycheck-clang-include-path "/usr/include/cairo")
  (add-to-list 'flycheck-clang-include-path "/usr/include/pixman-1")
  (add-to-list 'flycheck-clang-include-path "/usr/include/freetype2")
  (add-to-list 'flycheck-clang-include-path "/usr/include/libpng16")
  (add-to-list 'flycheck-clang-include-path "/usr/include/gdk-pixbuf-2.0")
  (add-to-list 'flycheck-clang-include-path "/usr/lib/x86_64-linux-gnu/glib-2.0/include")

  (add-to-list 'flycheck-clang-args "-lgtk-3")
  (add-to-list 'flycheck-clang-args "-lgdk-3")
  (add-to-list 'flycheck-clang-args "-lpangocairo-1.0")
  (add-to-list 'flycheck-clang-args "-lpango-1.0")
  (add-to-list 'flycheck-clang-args "-latk-1.0")
  (add-to-list 'flycheck-clang-args "-lcairo-gobject")
  (add-to-list 'flycheck-clang-args "-lcairo")
  (add-to-list 'flycheck-clang-args "-lgdk_pixbuf-2.0")
  (add-to-list 'flycheck-clang-args "-lgio-2.0")
  (add-to-list 'flycheck-clang-args "-lgobject-2.0")
  (add-to-list 'flycheck-clang-args "-lglib-2.0")
  )
(define-minor-mode gtk-mode ()
  (interactive)
  ;;  :lighter " GTK"
  )
(add-hook 'gtk-mode-hook 'my-gtk-mode-hook)

;; glib mode
(defun my-glib-mode-hook ()
  (add-to-list 'flycheck-clang-include-path "/usr/include/glib-2.0")
  (add-to-list 'flycheck-clang-include-path "/usr/lib/glib-2.0/include")

  (add-to-list 'flycheck-clang-args "-lglib-2.0"))

(define-minor-mode glib-mode ()
  (interactive)
  )
(add-hook 'glib-mode-hook 'my-glib-mode-hook)

;; sdl mode
(fset 'insert-SDL_
   "SDL_")

(defun my-sdl-mode-hook ()
  (add-to-list 'flycheck-clang-include-path "/usr/include/SDL2")

  (add-to-list 'flycheck-clang-args "-D_REENTRANT")
  (add-to-list 'flycheck-clang-args "-pthread")
  (add-to-list 'flycheck-clang-args "-lSDL2")

  )

(easy-mmode-define-minor-mode sdl-mode
							  "SDL"
							  nil
							  nil
  ;;  :lighter " SDL"
  )
(add-hook 'sdl-mode-hook 'my-sdl-mode-hook)

;; exec path from shell
(exec-path-from-shell-initialize)

;; go
(require 'auto-complete)
(require 'go-autocomplete)
(require 'auto-complete-config)
(ac-config-default)
(add-hook 'go-mode-hook 'flycheck-mode)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; other
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;
;; helm
(require 'helm)
(require 'helm-config)
;; helm-for-files -> "C-x b"
(define-key global-map (kbd "C-x b") 'helm-for-files)
;; helm-show-kill-ring -> "M-y"
(define-key global-map (kbd "M-y") 'helm-show-kill-ring)
;; use helm-c-moccur
(global-set-key (kbd "C-s") 'helm-occur)

;; helm-M-x
(define-key global-map (kbd "M-x") 'helm-M-x)

(require 'helm-config)

;;;;;;;;;;

;; ;; auto-complete
(when (require 'auto-complete-config nil t)
  (ac-config-default)
  (setq ac-use-menu-map t)
  (setq ac-ignore-case nil))

;; color-moccur
(when (require 'color-moccur nil t)
  ;; occur-by-occur -> "M-o"
  (define-key global-map (kbd "C-M-o") 'occur-by-moccur)
  ;; space to and
  (setq moccur-split-word t)
  ;; Exclude file, when search
  (add-to-list 'dmoccur-exclusion-mask "\\.DS_Store")
  (add-to-list 'dmoccur-exclusion-mask "^#.+#$"))

;; moccur-edit
(require 'moccur-edit nil t)
(defadvice moccur-edit-change-file
    (after save-after-moccur-edit-buffer activate)
  (save-buffer))

;; undohist
(when (require 'undohist nil t)
  (undohist-initialize))

;; undo-tree
(when (require 'undo-tree nil t)
  (global-undo-tree-mode))

;; point-history
(require 'point-history)
(point-history-mode t)
(define-key global-map (kbd "C-x p") 'point-history-show)
(define-key point-history-show-mode-map (kbd "C-n") 'point-history-next-line)
(define-key point-history-show-mode-map (kbd "C-p") 'point-history-prev-line)

;; helm-show-kill-ring
(define-key global-map (kbd "C-x o") 'helm-show-kill-ring)

;; elscreen
(setq elscreen-prefix-key (kbd "C-o"))
(when (require 'elscreen nil t)
  (elscreen-start))

;; point undo
(require 'ring)
(require 'edmacro)

(defvar-local jump-back!--marker-ring nil)

(defun jump-back!--ring-update ()
  (let ((marker (point-marker)))
    (unless jump-back!--marker-ring
      (setq jump-back!--marker-ring (make-ring 30)))
    (ring-insert jump-back!--marker-ring marker)))

(run-with-idle-timer 1 t 'jump-back!--ring-update)

(defun jump-back! ()
  (interactive)
  (if (ring-empty-p jump-back!--marker-ring)
      (error "No further undo information")
    (let ((marker (ring-ref jump-back!--marker-ring 0))
          (repeat-key (last-input-event)))
      (ring-remove jump-back!--marker-ring 0)
      (if (= (point-marker) marker)
          (jump-back!)
        (goto-char marker)
        (message "(Type %s to repeat)" (edmacro-format-keys repeat-key))
        (set-temporary-overlay-map
         (let ((km (make-sparse-keymap)))
           (define-key km repeat-key 'jump-back!)
           km))))))

(define-key global-map (kbd "M-/") 'jump-back!)


;; flycheck
(add-hook 'after-init-hook #'global-flycheck-mode)
(with-eval-after-load 'flycheck
  (flycheck-pos-tip-mode))
(define-key global-map (kbd "C-M-.") 'flycheck-next-error)
(define-key global-map (kbd "C-M-,") 'flycheck-previous-error)
(define-key global-map (kbd "C-c d") 'flycheck-list-errors)

;; 3 split
(defun split-window-horizontally-n (num_wins)
  (interactive "p")
  (dotimes (i (- num_wins 1))
    (split-window-horizontally))
  (balance-windows))
(global-set-key (kbd "C-x C-3") (lambda ()
                           (interactive)
                           (split-window-horizontally-n 3)))

;; disable mouse
(global-disable-mouse-mode)
(put 'erase-buffer 'disabled nil)

;; title
(require 'dashboard)
(dashboard-setup-startup-hook)
(setq dashboard-banner-logo-title "Urusainaxa bukkorosuyo?")
(setq dashboard-startup-banner "~/.emacs.d/picture/tica.png")
