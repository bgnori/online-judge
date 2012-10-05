


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

def ujm_g(D):
    """
    >>> g = ujm_g(13)
    >>> [g.next() for i in range(6)]
    [12, 14, 25, 27, 38, 40]
    """
    i = 1
    while True:
        yield D*i - 1
        yield D*i + 1
        i+=1

def find_y_with(y2):
    y = int(pow(y2, 0.5))
    return (y*y == y2) and y

def solve_for(D):
    count = 0
    for x in ujm_g(D):
        count += 1
        y2, m = divmod(x*x - 1, D)
        if m:
            continue
        found = find_y_with(y2)
        if found:
            return x, found
        if count > 1000*10000:
            break
    print 'problem with' ,D
    return 0, 0


if False:
    import doctest
    doctest.testmod()
else:
    largest = 0
    found = None
    for D in range(2, 1001):
        if not isSq(D):
            x, y = solve_for(D)
            #print D, x, y
            assert x*x - D*y*y - 1 == 0
            if x > largest:
                largest = x
                found = D
    print largest
    print found


