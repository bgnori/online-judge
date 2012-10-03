


def fact(n):
    '''
    >>> fact(0)
    1
    >>> fact(1)
    1
    >>> fact(5)
    120
    >>> fact(9)
    362880
    '''
    p = 1
    for i in range(1, n+1):
        p *= i
    return p

def foo(n):
    '''
    >>> foo(145)
    145
    '''
    xs = str(n)
    s = 0
    for x in xs:
        s += fact(int(x))
    return s

if False:
    import doctest
    doctest.testmod()
else:
    bound = fact(9) * 7
    s = 0
    for i in range(3, bound+1):
        k = foo(i)
        if k == i:
            s += i
    print s



