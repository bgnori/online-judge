
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
while count < 500:
    i += 1
    n = triangle(i)
    count = len(p.divisors(n))
print time.time() - start
print n

"""
count < 300
no-if/with-ith
   ncalls  tottime  percall  cumtime  percall filename:lineno(function)
 275706    0.057    0.000    0.057    0.000 {divmod} (no-if)
 149795    0.027    0.000    0.027    0.000 {divmod} (with-if)

"""

"""
count < 500
  3199661    0.567    0.000    0.567    0.000 {divmod} (with-if)
  3199661    0.656    0.000    0.656    0.000 {divmod}
"""
