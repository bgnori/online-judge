
import time
from libpe import primehelper as p


def triangle(n):
    """
    >>> triangle(1)
    1
    >>> triangle(5)
    15
    >>> triangle(7)
    28
    >>> triangle(10)
    55
    """
    return n*(n+1)/2

start =time.time()
count = 0
i = 0
while count < 300:
    i += 1
    n = triangle(i)
    count = len(p.divisors(n))
print time.time() - start
print n

