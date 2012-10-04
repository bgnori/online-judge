

def t(n):
    return n*(n+1)/2

class Triangles:
    '''
    >>> tt = Triangles()
    >>> 1 in tt
    True
    >>> 55 in tt
    True
    >>> 100 in tt
    False
    >>> 1000 in tt
    False

    '''
    def __init__(self):
        self.k = 0
        self.memo = set()

    def __contains__(self, n):
        if t(self.k) < n:
            self.extend(n)
        return n in self.memo

    def extend(self, n):
        v = t(self.k)
        while v < n:
            self.k+=1
            v = t(self.k)
            self.memo.add(v)



def alphpos(c):
    '''
    >>> alphpos('S')
    19
    >>> alphpos('k')
    11
    >>> alphpos('Y')
    25
    '''
    k = str.upper(c)
    return ord(k) - ord('A') + 1

def worth(word):
    '''
    >>> worth('SKY')
    55
    '''
    r = 0
    for c in word:
        r += alphpos(c)
    return r

def isTriangleWord(s):
    w = worth(s)


if False:
    import doctest
    doctest.testmod()
else:
    tt = Triangles()
    with open('0042/words.txt') as f:
        data = f.read()
    xs = data.split(',')
    words = set()
    for x in xs:
        s = x[1:-1]
        if worth(s) in tt:
            words.add(s)
    print words
    print len(words)

