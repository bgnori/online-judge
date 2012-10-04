


import peprime

p = peprime.Prime()


def cg_test(n):
    """
    >>> cg_test(9)
    (7, 1)
    >>> cg_test(15)
    (7, 2)
    >>> cg_test(21)
    (3, 3)
    >>> cg_test(25)
    (7, 3)
    >>> cg_test(35)
    (3, 4)
    """
    for i in range(2, n):
        if p.isprime(i):
            rest = n - i
            k = int(pow(rest/2, 0.5)) 
            if 2*k*k == rest:
                return (i, k)
    return ()


if False:
    import doctest
    doctest.testmod()
else:
    i = 33
    while cg_test(i):
        i += 2
        while p.isprime(i):
            i+=2 
    print i

