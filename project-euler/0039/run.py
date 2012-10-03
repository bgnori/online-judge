


def triangles_of(perimeter):
    '''
    >>> list(triangles_of(120))
    [(20, 48, 52), (24, 45, 51), (30, 40, 50)]
    '''
    for a in range(1, perimeter-1):
        for b in range(a, perimeter - a - 1):
            c = perimeter - a - b
            if c <= b:
                continue
            assert a <= b
            assert b < c
            if a*a + b*b == c*c:
                yield a, b, c

def count(g):
    i = 0
    for x in g:
        i+=1
    return i

if False:
    import doctest
    doctest.testmod()
else:
    m = 0
    j = 0
    for i in xrange(1, 1001):
        x = count(triangles_of(i))
        if x > m:
            m = x
            j = i
    print m, j

