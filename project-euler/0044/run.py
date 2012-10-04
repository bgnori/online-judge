

def pen(n):
    return n*(3*n-1)/2

'''
 assuming j < k won't destroy anything.
'''


class Pentagonals:
    """
    >>> x = Pentagonals()
    >>> 1 in x
    True
    >>> 35 in x
    True
    >>> 20 in x
    False
    >>> 100 in x
    False
    >>> 92 in x
    True

    """
    def __init__(self):
        self.max = 0
        self.memo = set()

    def __contains__(self, k):
        if pen(self.max) < k:
            self.extend(k)
        return k in self.memo

    def extend(self, k):
        v = pen(self.max)
        while v < k:
            self.max += 1
            v = pen(self.max)
            self.memo.add(v)

if False:
    import doctest
    doctest.testmod()
else:
    SEARCHRANGE = 10000
    x = Pentagonals()
    smallest = pen(SEARCHRANGE)
    for j in xrange(1, SEARCHRANGE):
        for k in xrange(j+1, SEARCHRANGE):
            if (pen(j) + pen(k)) in x and (pen(k) - pen(j)) in x:
                diff = pen(k) - pen(j)
                if diff < smallest:
                    smallest = diff
    print smallest


