


def palindrome(xs):
    """
    >>> palindrome('abc')
    False
    >>> palindrome('aba')
    True
    >>> palindrome('aa')
    True
    >>> palindrome('')
    True
    >>> palindrome('a')
    True
    """
    if len(xs) < 2:
        return True
    elif xs[0] == xs[-1]:
        return palindrome(xs[1:-1])
    else:
        return False

def binary(n):
    '''
    >>> binary(585)
    '1001001001'
    '''
    d, m = divmod(n, 2)
    if d:
        return binary(d) + str(m)
    else:
        return str(m)

def test(n):
    '''
    >>> test(585)
    True
    '''
    return palindrome(str(n)) and palindrome(binary(n))


if False:
    import doctest
    doctest.testmod()
else:
    s = 0
    for i in range(1000000):
        if test(i):
            s += i
    print s


