#lang plai

(define (read-list lst)
  (begin
    (define x (read))
    (if (eof-object? x)
        lst
        (read-list (append lst (list x))))))

(define (print-list lst)
  (match lst
    [(list x) (display x)]
    [(cons x xs)
     (begin
       (display x)
       (display "\n")
       (print-list xs))]))

(define lst (read-list '()))

(define (make-abs-list lst)
  (match lst
     ['() '()]
     [(cons x xs) (if (>= x 0)
                      (cons x (make-abs-list xs))
                      (cons (* -1 x) (make-abs-list xs)))]))

(print-list (make-abs-list lst))
