#!/usr/bin/python

def readints(line):
    return map(int, line.split())


def mark(d, p):
    m = d.get(p, 0)
    d[p] = m + 1

def chunker(f):
    while True:
        line = f.readline()
        n, r = readints(line)
        if n == 0 and r == 0:
            raise StopIteration
        tiles = set()
        v_test = set()
        h_test = set()
        for i in range(n): 
            line = f.readline()
            lbx, lby, rtx, rty = readints(line)

            w = rtx - lbx 
            h = rty - lby
            for x in range(lbx, rtx): 
                for y in range(lby, rty): 
                    tiles.add((x,y))
            for x in range(lbx-1, rtx): 
                v_test.add((x, rty-1))
                v_test.add((x, lby-1))
            for y in range(lby-1, rty): 
                h_test.add((lbx-1, y))
                h_test.add((rtx-1, y))

                            
        area = len(tiles)
        if r == 1:
            yield area,
        elif r == 2:
            edge = 0
            for x, y in v_test:
                p = x, y
                q = x, y+1
                if p in tiles and q not in tiles or p not in tiles and q in tiles:
                    edge += 1
            for x, y in h_test:
                p = x, y
                q = x+1, y
                if p in tiles and q not in tiles or p not in tiles and q in tiles:
                    edge += 1

            yield area, edge

import sys

for ans in chunker(sys.stdin):
    if len(ans) == 1:
        print ans[0]
    elif len(ans) == 2:
        print ans[0]
        print ans[1]
    else:
        pass


