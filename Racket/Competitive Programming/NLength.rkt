#lang racket

(define (f n)
  (my-sol n "["))

(define (my-sol n str)
  (if (= n 1)
      (string-append str (number->string n) "]")
      (my-sol (sub1 n) (string-append str (number->string n) ", "))))