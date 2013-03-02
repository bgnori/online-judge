#!/usr/bin/python

def readints(f):
    return map(int, f.readline().split())

def count(a, b, detours):
    xy = {}
    for i in range(0, a+1):
        xy[(i, 0)] = 0
    for j in range(0,  b+1):
        xy[(0, j)] = 0

    for i, j in detours:
        xy[(i, j)] = 0
    xy[(1, 1)] = 1

    for i in range(1, a+1):
        for j in range(1,  b+1):
            m = xy.get((i, j), None)
            if m is None:
                xy[(i,j)] = xy[(i-1, j)] + xy[(i, j-1)]
    return xy[(a,b)]

import sys

f = sys.stdin
a, b = readints(f)
while a and b:
    n, = readints(f)
    detours = set()
    for i in range(n):
        detours.add(tuple(readints(f)))
    print count(a, b, detours)
    a, b = readints(f)

