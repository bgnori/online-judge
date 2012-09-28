
is5or3 :: Integer -> Bool
is5or3 = \x -> (x `mod` 3 ==0 || x `mod` 5 ==0)

-- || (Eq 0 $ mod \x 5

main = print $ sum $ filter is5or3 $ take 999 [1..]
