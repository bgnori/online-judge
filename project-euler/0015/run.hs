
foo :: Int -> Int -> Int
foo i j
    | and [i == 0, j == 0] = 1
    | j == 0 = foo ( i - 1 ) j
    | j > i = foo j i -- i <= j  for any i, j
    | otherwise = foo (i - 1) j + foo i (j - 1)


-- main = print $ foo 0 0
main = print $ foo 20 20

