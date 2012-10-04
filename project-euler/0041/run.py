
import peprime


def permutation(xs):
    '''
        from 0024
    '''
    if len(xs) == 1:
        yield xs
    else:
        for i, x in enumerate(xs):
            for p in permutation(xs[:i]+xs[i+1:]):
                yield x+p


p = peprime.Prime()

k = 0
for s in permutation('1234567'):
    x = int(s)
    if p.isprime(x):
        if x > k:
            k = x

print k

