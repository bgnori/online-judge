
import peprime

p = peprime.Prime()



for i in xrange(2, 100):
    if len(set(p.decompose(i))) == 2 and len(set(p.decompose(i+1))) == 2 :
        print i
        break

for i in xrange(100, 1000):
    if len(set(p.decompose(i))) == 3 and \
       len(set(p.decompose(i+1))) == 3 and \
       len(set(p.decompose(i+2))) == 3:
        print i
        break

for i in xrange(100, 10000000):
    if len(set(p.decompose(i))) == 4 and \
       len(set(p.decompose(i+1))) == 4 and \
       len(set(p.decompose(i+2))) == 4 and \
       len(set(p.decompose(i+3))) == 4:
        print i
        break
