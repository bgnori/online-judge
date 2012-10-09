

def reverse_add(xs):
    """
    >>> reverse_add('349')
    '1292'
    >>> reverse_add('1292')
    '4213'
    >>> reverse_add('4213')
    '7337'
    """
    m = int(''.join(list(reversed(xs))))
    return str(m+int(xs))


def palindrome(xs):
    """
    >>> palindrome('abba')
    True
    >>> palindrome('aba')
    True
    >>> palindrome('abca')
    False

    """
    lxs = len(xs)
    if lxs == 0:
        return True
    elif lxs == 1:
        return True
    elif xs[0] == xs[-1]:
        return palindrome(xs[1:-1])
    else:
        return False


def testLychrel(n):
    """
    >>> testLychrel(349)
    3
    >>> testLychrel(10677)
    50
    """
    LIMIT = 50
    i = 0
    xs = str(n)
    while not palindrome(xs) and i < LIMIT:
        xs = reverse_add(xs)
        i += 1
    return i


if True:
    r = 0
    for i in xrange(10000):
        if testLychrel(i) == 50:
            r += 1
    print r #246

else:
    import doctest
    doctest.testmod()

