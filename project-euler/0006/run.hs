

sumofsqures :: [Int] -> Int
sumofsqures xs = foldr (+) 0 $ map (^2) xs

squareofsum :: [Int] -> Int
squareofsum xs = (foldr (+) 0 xs) ^ 2

diff :: [Int] -> Int
diff xs = squareofsum xs - sumofsqures xs

main = print $ diff [1..100]
-- 25164150

