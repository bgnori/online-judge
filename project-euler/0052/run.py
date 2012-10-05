def hash52(n):
    """
    >>> hash52(1234)
    1234
    >>> hash52(4321)
    1234
    >>> hash52(125874) == hash52(251748)
    True
    """
    xs = list(str(n))
    xs.sort()
    return int(''.join(xs))

def test(i):
    h = hash52(i)
    for j in range(2, 7):
        k = hash52(i*j)
        if k != h:
            return False
    return True


if False:
    import  doctest
    doctest.testmod()
else:
    import sys
    d = {}
    for i in xrange(1, int(sys.argv[1])):
        if test(i):
            print i
            break

