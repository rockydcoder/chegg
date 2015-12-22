; the function AreaOfCircle
; calculates area of a circle
; when the radius is input from keyboard

(defun ask-and-tell()
(terpri)
(princ "Enter Radius: ")
(setq radius (read))
(setq area (* 3.1416 radius radius))
(princ "Area: ")
(write area))
(ask-and-tell)