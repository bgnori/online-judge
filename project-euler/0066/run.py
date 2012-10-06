
import continuedfraction


def isSq(n):
    '''
    >>> isSq(4)
    True
    >>> isSq(169)
    True
    >>> isSq(149)
    False
    '''
    d = int(pow(n, 0.5))
    return d*d == n


def seq_fraction(cf):
    """
    >>> cf = continuedfraction.cf
    >>> g = seq_fraction(cf(2))
    >>> [g.next() for i in range(4)]
    [1, 2, 2, 2]
    >>> g = seq_fraction(cf(13))
    >>> [g.next() for i in range(11)]
    [3, 1, 1, 1, 1, 6, 1, 1, 1, 1, 6]

    """
    first, period = cf
    yield first #a0
    pl = len(period)
    count = 0
    while True:
        yield period[count % pl] #a1 and so on.
        count+=1


def omega_app_k(nth, cft):
    """
    >>> omega_app_k(0, (1, (2,))) #cf(2)
    (3, 2)
    >>> omega_app_k(0, (1, (1, 2))) #cf(3)
    (2, 1)
    >>> omega_app_k(0, (2, (4,))) #cf(5)
    (9, 4)
    """
    g = seq_fraction(cft)
    xs = [g.next() for i in range(nth+2)]
    xs.reverse()
    n, d = 0, 1
    for w in xs:
        n, d = d, n+d*w
    return d, n


def find_x_y(D):
    """
    >>> find_x_y(2)
    (3, 2)
    >>> find_x_y(3)
    (2, 1)
    >>> find_x_y(5)
    (9, 4)
    >>> find_x_y(6)
    (5, 2)
    >>> find_x_y(7)
    (8, 3)
    """
    cf = continuedfraction.cf(D)
    n = 0
    x, y = omega_app_k(0, cf)
    while x*x - D*y*y - 1:
        n+=1
        x, y = omega_app_k(n, cf)
        #print x, y, 1
    return x, y


if 0:
    import doctest
    doctest.testmod()
else:
    largest = 0
    found = 0
    for D in range(2, 1001):
        if isSq(D):
            continue
        x, y = find_x_y(D)
        if x > largest:
            largest = x
            found = D
    print largest
    print found

#39480499 1248483
#1000
