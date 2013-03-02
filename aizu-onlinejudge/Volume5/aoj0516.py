#!/usr/bin/python

import sys
def readints():
    return map(int, sys.stdin.readline().split())


n, k = readints()
while n and k:
    data = [readints()[0] for i in range(n)]

    window = sum(data[:k])
    L = window
    for i in range(k, n):
        window = window + data[i] - data[i-k]
        if window > L:
            L = window
    print L
    n, k = readints()

