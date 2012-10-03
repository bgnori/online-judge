

def pandigital(xs):
    """
    >>> pandigital("12")
    False
    >>> pandigital("11")
    False
    >>> pandigital("123456789")
    True
    """
    m = len(xs)
    g = set(xs)
    n = len(g)
    if m != n:
        return False
    for i in range(1, 10):
        if str(i) not in g:
            return False
    return True


def concatenated(n, xs):
    """
    >>> concatenated(192, (1, 2, 3))
    '192384576'
    >>> concatenated(9, (1, 2, 3, 4, 5))
    '918273645'
    """
    return ''.join([str(n*x) for x in xs])


if False:
    import doctest
    doctest.testmod()
else:
    m = 0
    for i in range(1, 10):
        for j in range(2, 10):
            xs = concatenated(i, range(1, j+1))
            if pandigital(xs):
                k = str(xs)
                if m < k:
                    m = k
    print m 
