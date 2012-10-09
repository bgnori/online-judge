


foo :: Int -> Int -> Bool
foo d n
    | d == 1 = True
    | n `mod` d == 0 = foo (d - 1) n
    | otherwise = False

insert :: Int -> [[Int]] -> [[Int]]
insert k divisors 
    | null divisors = [[k, 1]]
    | null $ head divisors = [[k, 1]]
    | (head $ head divisors) == k = [[k, succ $ last $ head divisors]] ++ tail divisors
    | otherwise = [[k, 1]] ++ divisors


helper :: Int -> Int -> [[Int]]
helper d x
    | d == x = insert d [[]]
    | x `mod` d == 0  = insert d $ helper d ( x `div` d )
    | otherwise = helper ( d + 1 ) x


decompose :: Int -> [[Int]]
decompose x 
    | x > 1 = helper 2 x
    | otherwise = [[]]


merge :: [[Int]] -> [[Int]] -> [[Int]]
merge xs ys
    | null xs = ys
    | null ys = xs
    | hhx == hhy = [[hhx, max hlx hly]] ++ merge (tail xs) (tail ys)
    | hhx > hhy = [head ys] ++ merge xs (tail ys)
    | hhx < hhy = [head xs] ++ merge (tail xs) ys
    where 
        hhx = head $ head xs 
        hhy = head $ head ys  
        hlx = head $ last xs
        hly = head $ last ys


components :: Int -> [[Int]]
components k 
    | k == 1 = []
    | k > 0 = merge (components (k-1)) (decompose k)

power :: [Int] -> Int
power xs = head xs ^ last xs

-- main = print $ foo 10 1000 -- False
-- main = print $ foo 10 2520 -- True
-- main = print $ head $ filter (foo 10) [1..] -- 2520
-- main = print $ head $ filter (foo 20) [1..]
-- main = print $ and $ map (> 10) [1,2,3,4,5]
-- main = print $ decompose 1001
-- main = print $ decompose 1
-- main = print $ decompose 9
-- main = print $ 2 ** 10
-- main = print $ 2 ^^ 10
-- main = print $ 2 ^ 10
main = print $ components 4
-- main = print $ foldl (*) 1 [1..10]
-- main = print $ foldl (*) 1 $ map power $ components 20


