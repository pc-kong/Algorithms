#lang plai

(define (read-list lst)
  (begin
    (define x (read))
    (if (eof-object? x)
        lst
        (read-list (append lst (list x))))))

(define numbers (read-list '()))
(define n (/ (- (length numbers) 2) 2))

(define (make-equation numbers pos val res)
  (if (= (- n 1) pos)
      res
      (make-equation (rest numbers) (add1 pos) val (cons (expt (* (get-ith numbers pos 0) val) (get-ith numbers (* 2 pos) 0)) res))))

(define (get-ith lst index pos)
  (if (or (= (- index 1) pos) (= pos 0))
      (first lst)
      (get-ith (rest lst) index (add1 pos))))

(print (make-equation numbers 0 (get-ith numbers (+ (* 2 n) 1) 0) '()))