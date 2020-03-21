;;; rings-autoloads.el --- automatically extracted autoloads
;;
;;; Code:

(add-to-list 'load-path (directory-file-name
                         (or (file-name-directory #$) (car load-path))))


;;;### (autoloads nil "rings" "rings.el" (0 0 0 0))
;;; Generated autoloads from rings.el

(autoload 'rings-generate-toggler "rings" "\


\(fn KEY)" nil t)

(defalias 'rings-generate-setter 'rings-generate-toggler)

(autoload 'rings-generate-adder "rings" "\


\(fn KEY)" nil t)

(autoload 'rings-generate-remover "rings" "\


\(fn KEY)" nil t)

(autoload 'rings-generate-cycler "rings" "\


\(fn KEY)" nil t)

(if (fboundp 'register-definition-prefixes) (register-definition-prefixes "rings" '("rings-")))

;;;***

;; Local Variables:
;; version-control: never
;; no-byte-compile: t
;; no-update-autoloads: t
;; coding: utf-8
;; End:
;;; rings-autoloads.el ends here
