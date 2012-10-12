
string2ints :: String -> [Int]
string2ints xs = map (\x -> read [x] :: Int) xs

fact :: Integer -> Integer
fact n
    | n == 0 = 1
    | otherwise = n * fact ( n - 1 )


-- main = print $ fact 20
main = print $ foldr (+) 0 $ string2ints $ show $ fact 100
