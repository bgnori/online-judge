
helper :: Int -> Int -> [Int]
helper d x
    | d == x = [d]
    | x `mod` d == 0  = [d] ++ helper d ( x `div` d)
    | otherwise = helper ( d + 1 ) x

decompose :: Int -> [Int]
decompose = \x -> helper 2 x

main = print $ last $ decompose 600851475143
