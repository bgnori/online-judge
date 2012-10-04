


def digits():
    xs = ''
    i = 0
    while True:
        if not xs:
            xs += str(i)
            i+=1
        c, xs = xs[0], xs[1:]
        yield c

g = digits()
ds = {}
find = (1, 10, 100, 1000, 10000, 100000, 1000000)
for i in xrange(1000001):
    d = g.next()
    #print d,
    if i in find:
        ds[i] = d

p = 1
for v in ds.values():
    p *= int(v)
print
print ds
print p

