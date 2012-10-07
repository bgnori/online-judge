import libpe


def take2outof(xs):
    """
    >>> list(take2outof([0, 1]))
    [(0, 1)]
    >>> list(take2outof([0, 1, 2]))
    [(0, 1), (0, 2), (1, 2)]
    """
    m = len(xs)
    r = []
    for i in range(m-1):
        for j in range(i+1, m):
            r.append((xs[i], xs[j]))
    return r

def encode(n):
    """
    >>> encode(11234)
    ('AA234',)
    >>> encode(12134)
    ('A2A34',)
    >>> encode(12345)
    ()
    >>> encode(11223)
    ('AA223', '11AA3')
    >>> encode(11123)
    ('AA123', 'A1A23', '1AA23')
    >>> encode(12344)
    ()
    >>> encode(11231)
    ('AA231',)
    """
    d = {}
    xs = str(n)
    ys = xs[:-1]
    for i, x in enumerate(ys):
        v = d.get(x, None)
        if v:
            v = v + (i,)
        else:
            v = (i,)
        d[x] = v

    marks = []
    for k, v in d.items():
        if len(v) > 1:
            marks.append(k)

    r = []
    for i in marks:
        for k, m in take2outof(d[i]):
            zs = list(xs)
            zs[k] = 'A'
            zs[m] = 'A'
            r.append(''.join(zs))

    return tuple(r)

def make_from(s, i):
    """
    >>> make_from('AA231', 1)
    11231
    """
    return int(s.replace('A', str(i)))

if False:
    import doctest
    doctest.testmod()
else:
    import sys
    libpe.primehelper.pomp2nth(int(sys.argv[1]))
    print 'primes', libpe.primehelper.count
    for p in libpe.primehelper.primes:
        ens = encode(p)
        if ens:
            for en in ens:
                #print 
                count = 0
                for i in range(10):
                    n = make_from(en, i)
                    if libpe.primehelper.isprime(n):
                        count += 1
                        #print n,
                if count > 7:
                    print
                    print 'found!'
                    print p
                    sys.exit()
    print
    print 'not found...'

