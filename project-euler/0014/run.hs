
collatz :: Int -> Int
collatz n
    | even n = n `div` 2
    | odd n = 3 *n +1

chains :: Int -> [Int]
chains n
    | n == 1 = [1]
    | otherwise =  [n] ++ (chains (collatz n))


-- main = print $ collatz 13 -- 40
-- main = print $ chains 13  -- [13,40,20,10,5,16,8,4,2,1]

-- main = print $ zip [1..20] $ map (length . chains) [1..20]
-- main = print $ maximum (\x-> last x)$ zip [1..20] $ map (length . chains) [1..20]

dumbcomp :: (Int, Int) -> (Int, Int) -> (Int, Int)
dumbcomp xs ys
    | lx > ly = xs
    | lx < ly = ys
    | lx == ly = xs
    where 
        lx = snd xs
        ly = snd ys

-- main = print $ foldr dumbcomp [0,0] [[1,2],[1,3], [1, 2]]

-- main = print $ foldr dumbcomp (0, 0) (zip [1..] $ map (length . chains) [1..20]) -- (18, 21)
-- main = print $ foldr dumbcomp (0, 0) (zip [1..] $ map (length . chains) [1..999999]) -- it takes too long time

chainsLength :: Int -> Int
chainsLength n
    | n == 1 = 1
    | otherwise =  succ $ chainsLength $ collatz n

-- main = print $ chainsLength 13 --  10 -- length [13,40,20,10,5,16,8,4,2,1]
-- main = print $ foldr dumbcomp (0, 0) (zip [1..] $ map chainsLength [1..20]) -- (18, 21)
-- main = print $ foldr dumbcomp (0, 0) (zip [1..] $ map chainsLength [1..999999]) -- still too long to done


