
import libpe


bound = 1000*1000
libpe.primehelper.pomp2bound(bound/20)

ps = libpe.primehelper.primes[:]
nth = len(ps)

longest = 0
seq = ()
r = 0
for i in range(nth-1):
    k = ps[i]
    for j in range(i+1, nth):
        k += ps[j]
        #print j - i, (i, j), k
        if k > bound:
            continue
        if libpe.primehelper.isprime(k):
            #print '*'
            if j - i > longest:
                longest = j - i
                seq = (i, j)
                r = k

print r, seq

