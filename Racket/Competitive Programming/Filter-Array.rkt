#lang plai

(define n (read))

(define (read-list lst)
  (begin
    (define x (read))
    (if (eof-object? x)
        lst
        (read-list (append lst (list x))))))

(define lst (read-list '()))

(define (my-filter lst pred elem)
  (match lst
    ['() '()]
    [(cons x xs) (if (pred x elem)
                     (cons x (my-filter xs pred elem))
                     (my-filter xs pred elem))]))

(define (print-list lst)
  (match lst
    [(list x) (display x)]
    [(cons x xs)
     (begin
       (display x)
       (display "\n")
       (print-list xs))]))

(print-list (my-filter lst (lambda (x y) (< x y)) n))

