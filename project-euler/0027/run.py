
import peprime 

p = peprime.Prime()

def g(a, b):
    def f(n):
        return n*n + a*n + b
    return f

def length(f):
    """
    >>> length(lambda n : n*n + n + 41)
    40
    >>> length(lambda n : n*n - 79* n + 1601)
    80
    """
    def testing(foo):
        i = 0
        while True:
            yield i, foo(i)
            i += 1

    for i, k in testing(f):
        if k < 1:
            break
        elif p.isprime(k):
            continue
        else:
            break
    return i

if False:
    import doctest
    doctest.testmod()
else:
    m = 0
    ma = -1000
    mb = -1000
    for a in range(-999, 1000):
        for b in range(-999, 1000):
            k = length(g(a, b))
            if m < k:
                print k, a, b
                m = k
                ma = a
                mb = b
    print m, ma, mb, ma*mb


