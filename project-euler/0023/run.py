
"""
28123


"""

from libpe import primehelper 

MAX = 28123

primehelper.pomp2bound(MAX)

def isabundant(n):
    if primehelper.isprime(n):
        return False
    else:
        if primehelper.d(n) > n:
            return True
    return False


abundants = []

for i in range(1, MAX+1):
    if isabundant(i):
        abundants.append(i)

count = len(abundants)

marks = [False for i in range(MAX+1)]

for i in range(count):
    for j in range(i, count):
        s = abundants[i] + abundants[j]
        if s <= MAX:
            marks[s] = True

r = 0 
for i in range(1, MAX+1):
    if not marks[i]:
        r += i
print marks[:25]
print r

