#!/usr/bin/python

from sys import stdin


while True:
    n = int(stdin.readline())
    if n == 0:
        break
    for i in xrange(n):
        cmd = stdin.readline()

