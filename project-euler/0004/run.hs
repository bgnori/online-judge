


palindrome :: String -> Bool
palindrome xs 
    | length xs == 0 = True
    | length xs == 1 = True
    | head xs == last xs = palindrome $ init $ tail xs
    | otherwise = False


palindromeI :: Int -> Bool -- looking bad
palindromeI n = palindrome (show n)


-- main = print $ palindrome "12345432"
main = print $ maximum $ filter palindromeI [n * m | n <-[100..999], m <- [100..999]]
