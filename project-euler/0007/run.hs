

-- MUST read this first, I think.
-- http://www.haskell.org/haskellwiki/Prime_numbers

sieve :: Int -> [Int] -> Bool
sieve n xs
    | null xs = True
    | n `mod` x == 0 = False
    | otherwise  = sieve n xs'
    where 
        x = head xs
        xs' = tail xs


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

isprime :: Int -> Bool
isprime k
    | (length ( tail xs)) > 1 = False
    | (head $ head xs) > 1 = False
    | otherwise = True
    where xs = decompose k

-- primes = filter (\x ->  sieve x (takeWhile  (< x*x) primes)) [2..]
-- this won't work.

primes = [ x | x <- [2..], isprime x]

-- main = print $ sieve 10 [2, 3, 5] -- False
-- main = print $ sieve 11 [2, 3, 5] -- True
-- main = print $ sieve 2 [] -- True
-- main = print $ sieve 3 [2] -- True

main = print $ take 10 primes

