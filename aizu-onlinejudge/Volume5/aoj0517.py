#!/usr/bin/python

import sys
def readints():
    return map(int, sys.stdin.readline().split())

n, k = readints()

while n and k:
    xs = [False for i in range(n+2)]
    for i in range(k):
        x, = readints()
        xs[x] = True

    last = 0
    before = 1
    longest = 0
    #print 'i, longest, last, before'
    for i in range(1, n+2):
        x = xs[i]
        if x:
            pass
        elif xs[0]:
            """
            0123456789
            0-x--x--x-
            i = 8

            """
            #print i, longest, last, before
            longest = max(longest, i - last -1, i - before -1)
            before = last
            last = i
        else:
            longest = max(longest, i - last-1)
            last = i
    print longest
    n, k = readints()

