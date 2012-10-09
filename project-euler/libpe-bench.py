
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
  3199661    0.656    0.000    0.656    0.000 {divmod} foo
  3199661    0.559    0.000    0.559    0.000 {divmod} undo
  3209085    0.567    0.000    0.567    0.000 {divmod} if/while

"""
"""
initial: 9.073 CPU sec
    12375 2.233 0.000 3.600 0.000 run.py:50(decompose)
    12375 4.594 0.000 9.031 0.001 run.py:68(divisors)

after:  5.737 CPU sec
   562549    1.260    0.000    1.527    0.000 libpe.py:13(combination)
    12375    1.425    0.000    2.040    0.000 libpe.py:150(decompose)
    12375    1.697    0.000    5.696    0.000 libpe.py:182(divisors)
"""
