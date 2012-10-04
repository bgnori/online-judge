
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

def test(xs):
    """
    >>> test('1406357289')
    True
    """
    ps = [1, 2, 3, 5, 7, 11, 13, 17]

    if xs[0] == '0':
        return False
    for i in range(1, 8):
        k = int(xs[i:i+3])
        if k % ps[i]:
            return False
    return True

if False:
    import doctest
    doctest.testmod()
else:
    r = 0
    for s in permutation('0123456789'):
        if test(s):
            r += int(s)
    print r



