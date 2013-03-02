#!/usr/bin/python

import sys
def readints():
    return map(int, sys.stdin.readline().split())

def distance(p, q):
    dx = p[0] - q[0]
    dy = p[1] - q[1]
    return dx*dx + dy*dy


def uf(nodes, edges):
    retrun []

def find_square(gs):
    for g in gs:
        if len(g) != 4:
            continue
        if is_square(g):
            return g
    return None


n, = readints()

while n:
    ps = [tuple(readints()) for i in range(n)]

    lx = {}
    found = None
    for i, p in enumerate(ps):
        for q in ps[i+1:]:
            d = distance(p, q)
            m = lx.get(d, None)
            if m is None:
                m = []
            m.append((p, q))
            lx[d] = m
    lx = sorted(lx.iteritems(), key=lambda t:-t[0])
    for d2, edges in lx:
        if len(edges) < 4:
            continue
        print d2
        nodes = set()
        for p, q in edges:
            nodes.add(p)
            nodes.add(q)
        gs = uf(nodes, edges)
        found = find_square(gs)
        if found:
            break
    if found:
        print find_area(g)
    else:
        print 0

    n, = readints()


