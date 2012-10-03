

import peprime

def rotate(n):
    """
    >>> [p for p in rotate(123)]
    [123, 231, 312]
    >>> [p for p in rotate(1234)]
    [1234, 2341, 3412, 4123]
    """
    xs = str(n)
    k = len(xs)
    for i in range(k):
        yield int(xs[i:] + xs[:i])

def test(p, n):
    for k in rotate(n):
        if not p.isprime(k):
            return False
    return True

def find(n):
    """
    >>> sorted(list(find(100)))
    [2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97]
    """
    found = set()
    p = peprime.Prime()

    for i in range(2, n+1):
        if test(p, i):
            found.add(i)
    return found

if False:
    import doctest
    doctest.testmod()
else:
    print len(find(1000000))
    



