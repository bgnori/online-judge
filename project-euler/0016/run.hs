

string2ints :: String -> [Int]
string2ints xs = map (\x -> read [x] :: Int) xs



main = print $ foldr (+) 0 $ string2ints $ show (2^1000)

