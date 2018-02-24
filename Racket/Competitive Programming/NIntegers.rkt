#lang plai

(define (print-list-times lst n)
  (match lst
    [(list x) (print-times x n)]
    [(cons x xs)
     (begin
       (print-times x n)
       (display "\n")
       (print-list-times xs n))]))

(define (print-times elem n)
  (if (= n 1)
      (display elem)
      (begin
        (display elem)
        (display "\n")
        (print-times elem (sub1 n)))))

(define (read-list lst)
  (begin
    (define x (read))
    (if (eof-object? x)
        lst
        (read-list (append lst (list x))))))
    
(define n (read))
(define lst (read-list '()))
(print-list-times lst n)
