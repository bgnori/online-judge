#!/usr/bin/python


def chunker(f):
    while True:
        line = f.readline()
        line = line.strip()
        #header
        cups, limit = line.split()
        cups = int(cups)
        limit = int(limit)
        if cups ==0 and limit ==0:
            raise StopIteration
        r = [0, 0, 0]
        for i in range(3):
            line = f.readline()
            line = line.strip()
            xs = line.split()
            r[i] = [int(x) for x in xs[1:]]
        yield cups, limit, r


def make_tribit(r):
    d = {}
    for i, xs in enumerate(r):
        for x in xs:
            d[x] = i
    return d.values()


def decode(t, n):
    if n == 1:
        return t[0]
    else:
        s = decode(t[1:], n-1)
        if t[0] == 0:
            return s
        elif t[0] == 1:
            return 2*3**(n-1) - s
        else:
            return 2*3**(n-1) + s


if __name__ ==  "__main__":
    from StringIO import StringIO
    testf = StringIO("""3 10
0
1 1
2 2 3
4 20
2 1 2
1 3
1 4
2 5
2 1 2
0
0
3 3
0
1 1
2 2 3
0 0""")
    for data in chunker(testf):
        print data
        d = make_tribit(data[2])
        print d
        m = decode(d, data[0])
        m = min(m, 3**data[0] - m)
        if m > data[1]:
            print -1
        else:
            print m
        

