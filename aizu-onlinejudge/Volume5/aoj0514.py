#!/usr/bin/python
# -*- coding=utf8 -*-

"""
 a, b, c, N は 1 ≤ a, b, c ≤ 100, 1 ≤ N ≤ 1000 を満たす. 
"""

def readints(line):
    return map(int, line.split())

def solve(constraint, a, b, c):
    status = [2 for i in range(a+b+c+1)]
    for x, y, z, ok in constraint:
        if ok:
            status[x] = 1
            status[y] = 1
            status[z] = 1

    for x, y, z, ok in constraint:
        if not ok:
            if status[x] == 1 and status[y] == 1:
                status[z] = 0
            if status[y] == 1 and status[z] == 1:
                status[x] = 0
            if status[z] == 1 and status[x] == 1:
                status[y] = 0

    return status

def bar(f):
    a, b, c = readints(f.readline())
    while a and b and c:
        N, = readints(f.readline())
        constraint =  [readints(f.readline()) for i in range(N)]
        for r in solve(constraint, a, b, c)[1:]:
            print r
        a, b, c = readints(f.readline())


if True:
    import sys
    bar(sys.stdin)
else:
    sample_in = """2 2 2
4
2 4 5 0
2 3 6 0
1 4 5 0
2 3 5 1
0 0 0
"""
    # expected output
    """
2
1
1
0
1
0
"""
    from StringIO import StringIO
    foo = StringIO(sample_in)
    bar(foo)

