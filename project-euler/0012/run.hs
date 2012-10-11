

-- triangls = [foldr (+) 0 [1..n] | n <- [1..]] -- definition 
triangls = [ n * (n+1) `div` 2 | n <- [1..]] -- faster


main = print $ take 10 triangls
