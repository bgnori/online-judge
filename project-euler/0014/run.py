#!/usr/bin/python
# coding=utf8



class Collatz:
    def __init__(self):
        self.memo = {1:1}

    def step(self, n):
        if n%2:
            return 3*n + 1
        else:
            return n/2

    def chain(self, n):
        u'''
        13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

        >>> c = Collatz()
        >>> c.chain(13)
        10
        '''
        if n in self.memo:
            return self.memo[n]
        xs = []
        m = n
        while m not in self.memo:
            xs.append(m)
            m = self.step(m)
            #print m
        xs.reverse()
        found = self.memo[m]
        for i, x in enumerate(xs):
            self.memo[x] = found + i + 1
        return self.memo[n]

#import doctest
#doctest.testmod()

c = Collatz()
print c.chain(1)
print c.chain(13)
#print memo
longest = 0
n = 0

for i in xrange(2, 1000000):
    if i % 1000 == 0:
        print '.',
    k = c.chain(i)
    if k > longest:
        longest = k
        n = i
print n, longest







