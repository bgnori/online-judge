
"""
>>> decompose(13195)
[5, 7, 13, 29]
"""

def decompose(n):
    r = []
    i = 2
    while i < n:
        d, m = divmod(n, i)
        if m == 0:
            n = d
            r.append(i)
        else:
            i += 1
    r.append(n)
    return r

#import doctest
#doctest.testmod()
print decompose(600851475143)[-1]


