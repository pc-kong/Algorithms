#lang racket

(define n (read))

(define hash (make-hash (list (cons 0 1))))

(define (fact/memo n)
  (let [(val (hash-ref hash n 'null))]
    (if (equal? val 'null)
        (begin
          (hash-set! hash n (* n (fact/memo (- n 1))))
          (hash-ref hash n))
        val)))

(define (read-by-n n lst)
  (if (= n 0)
      lst 
      (cons (read) (read-by-n (sub1 n) lst))))

(define lst (read-by-n n '()))

(define (calculate-euler x exp res)
  (if (= exp 10)
      res
      (calculate-euler x (add1 exp) (+ res (/ (expt x exp) (fact/memo exp))))))

(define (print-result lst)
  (match lst
    [(list x) (display (calculate-euler x 0 0))]
    [(cons x xs)
     (begin
       (display (calculate-euler x 0 0))
       (display "\n")
       (print-result xs))]))

(print-result lst)
    