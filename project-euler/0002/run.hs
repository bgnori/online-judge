


fib@(1:tfib) = 1:1:[ a+b | (a,b) <- zip fib tfib ]
main = print $ sum $ filter even $ takeWhile (<4000000) fib


