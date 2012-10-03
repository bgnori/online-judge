


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

g = set()
for xs in permutation('123456789'):
    for i in range(1, 8):
        for j in range(i+1, 9):
            x = int(xs[j:])
            if int(xs[:i]) * int(xs[i:j]) == x:
                g.add(x) 
print sum(g)
