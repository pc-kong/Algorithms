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

(define (filter-pos lst pos)
  (match lst
    ['() '()]
    [(cons x xs) (if (odd? pos)
                     (cons x (filter-pos xs (add1 pos)))
                     (filter-pos xs (add1 pos)))]))

(print-list (filter-pos lst 0))