
def tri(n):
    return n*(n+1)/2


def pen(n):
    """
    from 0044
    """
    return n*(3*n-1)/2

def hex(n):
    return n*(2*n-1)

class Holder:
    """
    >>> p = Holder(pen)
    >>> 1 in p
    True
    >>> 35 in p
    True
    >>> 20 in p
    False
    >>> 100 in p
    False
    >>> 92 in p
    True
    >>> h = Holder(hex)
    >>> 1 in h
    True
    >>> 45 in h
    True
    >>> 44 in h
    False
    >>> t = Holder(tri)
    >>> 40755 in t
    True
    >>> 40755 in h
    True
    >>> 40755 in p
    True

    """
    def __init__(self, f):
        self.max = 0
        self.memo = set()
        self.f = f

    def __contains__(self, k):
        if self.f(self.max) < k:
            self.extend(k)
        return k in self.memo

    def extend(self, k):
        v = self.f(self.max)
        while v < k:
            self.max += 1
            v = self.f(self.max)
            self.memo.add(v)

if False:
    import doctest
    doctest.testmod()
else:
    t = Holder(tri)
    p = Holder(pen)
    h = Holder(hex)
    count = 0
    i = 1
    try:
        while count < 3:
            n = hex(i)
            if n in t and n in p:
                print n
                print 'with', t.max, p.max, i #h.max
                count +=1
            i += 1
    except KeyboardInterrupt:
        print 'terminated by KeyboardInterrupt, i= ', i
        print len(t.memo), len(p.memo), len(h.memo)



