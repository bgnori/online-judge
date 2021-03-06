
def frac(n):
    """
    >>> frac(2)
    ((5,), ())
    >>> frac(3)
    ((), (3,))
    >>> frac(4)
    ((2, 5), ())
    >>> frac(5)
    ((2,), ())
    >>> frac(6)
    ((1,), (6,))
    >>> frac(7)
    ((), (1, 4, 2, 8, 5, 7))
    >>> frac(8)
    ((1, 2, 5), ())
    >>> frac(9)
    ((), (1,))
    >>> frac(10)
    ((1,), ())
    >>> frac(101)
    ((0, 0), (9,))
    """
    r = []
    m = 1 
    m = m*10
    d, m = divmod(m, n)
    while d not in r or (d == 0 and m != 0):
        r.append(d)
        m = m*10
        d, m = divmod(m, n)
    fixpart = []
    looppart = []
    for i,x in enumerate(r):
        #print i, x
        if x != d:
            fixpart.append(x)
        else:
            if m:
                looppart = r[i:]
            break;
    return tuple(fixpart), tuple(looppart)

if False:
    import doctest
    doctest.testmod()
else:
    m = 0
    for i in range(2, 1000):
        _, recuuring = frac(i)
        n = len(recuuring)
        if m <= n:
            print i
            m = n
            j = i
    print j, m
    print frac(j)
 
