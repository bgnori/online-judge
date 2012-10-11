
foo :: Int -> Int -> Int
foo i j
    | and [i == 0, j == 0] = 1
    | j == 0 = foo ( i - 1 ) j
    | j > i = foo j i -- i <= j  for any i, j
    | otherwise = foo (i - 1) j + foo i (j - 1)

memo_foo :: Int -> Int -> Int
memo_foo = (map foo [0..] [0..] !!) -- i j
    where
        foo i j 
            | and [i == 0, j == 0] = 1
            | j == 0 = memo_foo ( i - 1 ) j
            | j > i = memo_foo j i -- i <= j  for any i, j
            | otherwise = memo_foo (i - 1) j + memo_foo i (j - 1)

-- main = print $ foo 0 0
main = print $ memo_foo 2 2
-- main = print $ foo 20 20

