
import peprime


p = peprime.Prime()


def test(n):
    """
    >>> test(3)
    True
    >>> test(12)
    False
    >>> test(3797)
    True
    """
    if not p.isprime(n):
        return False
    xs = str(n)
    k = len(xs)
    for i in range(1, k):
        left = int(xs[i:])
        right = int(xs[:k-i])
        if not p.isprime(right) or not p.isprime(left):
            return False
    return True


if False:
    import doctest
    doctest.testmod()
else:
    i = 10
    found = []
    while len(found) < 11:
        if test(i):
            found.append(i)
        i+=1
    print found
    print sum(found)



