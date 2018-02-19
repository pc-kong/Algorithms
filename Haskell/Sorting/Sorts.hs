module Sorts where

minim :: Ord a => [a] -> a
minim [x] = x
minim (x:(y:ys)) = if x < y
                     then (minim (x:ys))
                     else (minim (y:ys))

insertionSort :: Ord a => [a] -> [a]
insertionSort [] = []
insertionSort ls = let m = (minim ls) in
                     m:(insertionSort [x | x <- ls, x/=m])

quickSort :: Ord a => [a] -> [a]
quickSort [] = []
quickSort (x:xs) = (quickSort [x' | x' <- xs, x' <= x])
                   ++ [x] ++ (quickSort [x' | x' <- xs, x' > x])
