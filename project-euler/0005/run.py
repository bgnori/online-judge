
"""
>>> map(decompose, [2, 3, 4, 5])
[[2], [3], [2, 2], [5]]
>>> unify(map(decompose, [2, 3, 4, 5]))
{2: 2, 3: 1, 5: 1}

>>> build(unify(map(decompose, [2, 3, 4, 5, 6, 7, 8, 9, 10])))
2520
"""

def decompose(n):
    r = []
    i = 2
    while i < n:
        d, m = divmod(n, i)
        if m == 0:
            n = d
            r.append(i)
        else:
            i += 1
    r.append(n)
    return r

def make(xs):
    d = {}
    for x in xs:
        v = d.get(x, 0)
        d[x] = v+1
    return d

def merge(e, f):
    d = {}
    g = set(e.keys()) | set(f.keys())
    for k in g:
        d[k] = max(e.get(k, 0), f.get(k, 0))
    return d

def unify(xss):
    d = {}
    for xs in xss:
        d = merge(d, make(xs))
    return d

def build(d):
    p = 1
    for k, v in d.iteritems():
        for i in range(v):
            p *= k
    return p


#import doctest
#doctest.testmod()


print build(unify(map(decompose, range(2, 21))))

