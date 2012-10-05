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


if False:
    import doctest
    doctest.testmod()
else:
    import sys
    libpe.primehelper.pomp2bound(int(sys.argv[1]))
    print libpe.primehelper.count
    d = {}
    for p in libpe.primehelper.primes:
        ens = encode(p)
        if ens:
            for en in ens:
                v = d.get(en, None)
                if v is None:
                    v = []
                v.append(p)
                d[en] = v

    print len(d)
    longest_len = 0
    longest_list = []
    longest_en = ''
    for k, v in d.iteritems():
        #print k, v, len(v)
        vlen = len(v)
        if vlen == 8:
            print k
            print v
        if vlen > longest_len:
            longest_len = vlen
            longest_list = v
            longest_en = k

    print longest_len
    print longest_en
    print longest_list

