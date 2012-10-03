

def permutation(xs):
    if len(xs) == 1:
        yield xs
    else:
        for i, x in enumerate(xs):
            for p in permutation(xs[:i]+xs[i+1:]):
                yield x+p



for i, s in enumerate(permutation('0123456789')):
    if i == (1000000 - 1):
        print s
        break

