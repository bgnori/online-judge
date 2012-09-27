#!/usr/bin/python

def f(a, b):
    return b, a+b

def fib(bound):
    a = 0
    b = 1
    while (a<bound):
        a, b = f(a, b)
        yield a

sum = 0
i = fib
for i in fib(4000000):
    if i%2 == 0:
        sum +=i
print sum


