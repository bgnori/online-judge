

import libpe



for i in range(1000, 10000):
    if libpe.primehelper.isprime(i):
        xs = str(i)
        d = {}
        known = set()
        known.add(i)
        for ys in libpe.permutation(xs):
            k = int(ys)
            if k in known:
                continue
            if k < 1000:
                continue 
            if not libpe.primehelper.isprime(k):
                continue
            if abs(k - i) in d:
                print k, i, d[abs(k-i)], abs(k-i)
            else:
                d[abs(k-i)] = k
                known.add(k)

