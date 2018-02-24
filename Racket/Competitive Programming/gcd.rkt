#lang plai

(define (gcd a b)
  (cond
    [(= 0 a) b]
    [(= 0 b) a]
    [(or (= 1 a) (= 1 b)) 1]
    [(< a b) (gcd a (remainder b a))]
    [else (gcd (remainder a b) b)]))

(define a (read))
(define b (read))

(print (gcd a b))