
def op(xs):
    """
    >>> op("122244")
    '113224'
    >>> op("44444444444")
    '114'
    """
    ys = ''
    last = 0
    r = 0
    for i, x in enumerate(xs):
        if xs[last]== x:
            r+=1
        else:
            ys = ys + "%d%s"%(r, xs[last])
            r = 1
            last = i
    ys = ys + "%d%s"%(r, xs[last])
    return ys

def mut(n, xs):
    """
    >>> mut(5, '11')
    '13112221'
    """
    for i in xrange(n):
        xs = op(xs)
    return xs

def chunk(f):
    """
    """
    while True:
        line = f.readline()
        n = line.strip()
        n = int(n)
        if n == 0:
            raise StopIteration
        line = f.readline()
        xs = line.strip()
        yield mut(n, xs)

import sys
for c in chunk(sys.stdin):
    print c

