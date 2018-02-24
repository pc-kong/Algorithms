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

(define (sum-odd lst n)
  (match lst
    ['() n]
    [(cons x xs) (if (odd? x)
                     (sum-odd xs (+ n x))
                     (sum-odd xs n))]))

(display (sum-odd lst 0))
