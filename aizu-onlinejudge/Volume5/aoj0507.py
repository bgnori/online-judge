


def square(n, height):
    if n == 0:
        yield ()
    else:
        for i in range(min(n, height),0, -1):
            for x in square(n-i, i):
                yield ('%d'%(i,),) + x 

def chunker(f):
    while True:
        line = f.readline()
        line = line.strip()
        n = int(line)
        if n == 0:
            raise StopIteration
        for s in square(n, n):
            yield s

import sys
for s in chunker(sys.stdin):
    print ' '.join(s)

