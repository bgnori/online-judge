#!/usr/bin/python

def readints(line):
    return map(int, line.split())

def cut(xs, k):
    return xs[k:] + xs[:k] 

def reffle(xs):
    ys = xs[:]
    k = len(ys)/2
    for i in range(k):
        xs[i*2] = ys[i]
        xs[i*2+1] = ys[i+k]
    return xs


def shuffler(f):
    n, = readints(f.readline())
    xs = list(range(1, 2*n+1))
    m, = readints(f.readline())
    for i in range(m):
        k, = readints(f.readline())
        if k == 0:
            xs = reffle(xs)
        else:
            xs = cut(xs, k)
    for x in xs:
        print x


import sys
shuffler(sys.stdin)
