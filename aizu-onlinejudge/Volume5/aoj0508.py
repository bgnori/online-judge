#!/usr/bin/python

def foo(nw, visited):
    last = visited[-1]
    r = 0
    for k in nw[last]:
        if k not in visited:
            v = foo(nw, visited + (k,))
        else:
            v = len(visited)
        if r < v:
            r = v
    return r

def findlongetstpath(nw):
    return max([foo(nw, (k,)) for k in nw.keys()])

def chunker(f):
    while True:
        line = f.readline()
        line = line.strip()
        dsize = int(line)
        if dsize == 0:
            raise StopIteration
        network = {}
        for i in range(dsize):
            line = f.readline()
            line = line.strip()
            s, d = line.split()
            rel = network.get(s, None)
            if rel is None:
                rel = set()
            rel.add(d)
            network[s] = rel
            rel = network.get(d, None)
            if rel is None:
                rel = set()
            rel.add(s)
            network[d] = rel
        yield network

import sys
for nw in chunker(sys.stdin):
    print findlongetstpath(nw)

