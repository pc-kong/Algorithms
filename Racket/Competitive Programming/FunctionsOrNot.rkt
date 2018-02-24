#lang plai

(define times (read))

(define (run-til-times made times)
  (if (< made times)
      (begin
        (let* [(tuples (read))
               (elems (read-lines tuples 0 '()))
               (result (my-map determine-function (make-hash (list (cons (car elems) (car (rest elems))))) (cddr elems)))]
          (print result))
        (run-til-times (add1 made) times))
      exit))

(define (read-lines tuples times-read lst)
  (if (= tuples times-read)
      lst
      (read-lines tuples (add1 times-read) (append lst (list (read) (read))))))

(define (my-map func hash lst)
  (match lst
    ['() "YES"]
    [(cons x (cons y ys))
     (begin
       (func hash x y)
       (my-map func hash ys))]))

(define (determine-function hash x y)
  (if (hash-has-key? hash x)
      "NO"
      (hash-set! hash x y)))

(run-til-times 0 times)