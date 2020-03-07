;;; test





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

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; keybinding
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; mykie
(require 'mykie)

;; backspace -> "C-h"
(define-key key-translation-map (kbd "C-h") (kbd "<DEL>"))
;; forward-word -> "C-." / backward-word -> "C-,"
(define-key global-map (kbd "C-.") 'forward-word)
(define-key global-map (kbd "C-,") 'backward-word)
;; kill-word -> "C-u"
(define-key global-map (kbd "C-u") 'backward-kill-word)
;; kill-whole-line -> "C-k"
(define-key global-map (kbd "C-k") 'kill-whole-line)
;; forward-list -> "M-." / backward-word -> "M-,"
(define-key global-map (kbd "M-.") 'forward-list)
(define-key global-map (kbd "M-,") 'backward-list)
;; forward-sentence -> "M-n" / backward-sentence -> "M-p"
(define-key global-map (kbd "M-n") 'forward-paragraph)
(define-key global-map (kbd "M-p") 'backward-paragraph)
;; new-and-indent -> "C-m"
(define-key global-map (kbd "C-m") 'newline-and-indent)
;; toggle-truncate-lines -> "C-c l"
(define-key global-map (kbd "C-c l") 'toggle-truncate-lines)
;; transpose-chars -> "C-t"
(define-key global-map (kbd "C-t") 'other-window)

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
(mykie:set-keys nil
  "C-<up>" 
  :default     move-line-up
  :region      move-region-up
  "C-<down>"
  :default     move-line-down
  :region      move-region-down
  )

;; duplicate thing
(require 'duplicate-thing)
(define-key global-map (kbd "M-c") 'duplicate-thing)

;; recenter3
;; I hate moving to the bottom and top of recenter-top-bottom(C-l).
;; Replace recenter-top-bottom to recenter3
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
          (recenter3-width (truncate (/ (window-body-height) 6.0))))
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
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

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

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; edit
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; width of TAB
(setq-default tab-width 4)

;; Do not use tabs word
(setq-default indent-tabs-mode nil)


;; display match branket
(setq show-paren-delay 0)
(show-paren-mode t)

;; on electric-pair-mode
(electric-pair-mode 1)

;; c++
(defun my-c++-mode-hook ()
  (setq c-basic-offset 4)
  (c-set-offset 'substatement-open 0))
(add-hook 'c++-mode-hook 'my-c++-mode-hook)

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

;; helm keybinding

;;;;;;;;;;

;; auto-complete
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

;; elscreen
(setq elscreen-prefix-key (kbd "C-o"))
(when (require 'elscreen nil t)
  (elscreen-start))

;; flycheck
(add-hook 'after-init-hook #'global-flycheck-mode)
(with-eval-after-load 'flycheck
  (flycheck-pos-tip-mode))

;; howm
(setq howm-directory (concat user-emacs-directory "howm"))
(setq howm-file-name-format "%Y/%m/%Y-%m-%d.howm")
(when (require 'howm-mode nil t)
  (define-key global-map(kbd "C-x C-c") 'howm-menu)
  (set-face-foreground 'howm-mode-title-face "gray90")
  )
(defun howm-save-buffer-and-kill ()
  (interactive)
  (when (and (buffer-file-name)
             (howm-buffer-p))
    (save-buffer)
    (kill-buffer nil)))
(define-key howm-mode-map (kbd "C-c C-c") 'howm-kill-all)

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
