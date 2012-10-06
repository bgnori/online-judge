

"""
    from solution of pe 64


"""

def opA(base, p_n, q_n):
    """
         p_n                 r(base)+q_n         
    -------------  =(opA)=> -------------
    r(base) - q_n              p_(n+1)

    >>> opA(23, 1, 4)
    7
    >>> opA(23, 7, 3)
    2
    >>> opA(23, 2, 3)
    7
    >>> opA(23, 7, 4)
    1
    """
    assert q_n > 0
    assert p_n > 0
    return (base - q_n*q_n )/ p_n #p_(n+1)


def opB(base, q_n, p_npp):
    """
      r(base)+q_n                      r(base) - q_(n+1)
    --------------- =(opB)=> a_(n+1) + -----------------
         p_n+1                              p_(n+1)

    >>> opB(23, 4, 7)
    (1, 3)
    >>> opB(23, 3, 2)
    (3, 3)
    >>> opB(23, 3, 7)
    (1, 4)
    >>> opB(23, 4, 1)
    (8, 4)
    >>> opB(23, 0, 1)
    (4, 4)
    >>> opB(2, 0, 1)
    (1, 1)
    >>> opB(3, 0, 1)
    (1, 1)
    >>> opB(9, 0, 1)
    (3, 3)
    """
    assert p_npp > 0
    assert q_n >= 0
    a = int((pow(base, 0.5)+q_n)/p_npp)
    return a, a * p_npp - q_n  #a_(n+1), q_(n+1)

class SQRTException(Exception):
    pass

def step(base, p_n, q_n):
    '''
         p_n                 r(base)+q_n         
    -------------  =(opA)=> -------------
    r(base) - q_n              p_(n+1)


      r(base)+q_n                      r(base) - q_(n+1)
    --------------- =(opB)=> a_(n+1) + -----------------
         p_n+1                              p_(n+1)

    >>> step(23, 1, 4)
    (1, 7, 3)
    >>> step(23, 7, 3)
    (3, 2, 3)
    >>> step(23, 2, 3)
    (1, 7, 4)
    >>> step(23, 7, 4)
    (8, 1, 4)
    '''
    assert p_n > 0
    assert q_n > 0
    p_npp = opA(base, p_n, q_n)
    if p_npp == 0:
        raise SQRTException
    assert p_npp > 0
    a, q_npp = opB(base, q_n, p_npp)
    assert a > 0
    assert q_npp > 0
    return a, p_npp, q_npp


def cf(base):
    """
    >>> cf(2)
    (1, (2,))
    >>> cf(3)
    (1, (1, 2))
    >>> cf(5)
    (2, (4,))
    >>> cf(6)
    (2, (2, 4))
    >>> cf(7)
    (2, (1, 1, 1, 4))
    >>> cf(8)
    (2, (1, 4))
    >>> cf(9)
    (3, ())
    >>> cf(10)
    (3, (6,))
    >>> cf(11)
    (3, (3, 6))
    >>> cf(12)
    (3, (2, 6))
    >>> cf(13)
    (3, (1, 1, 1, 1, 6))
    >>> cf(23)
    (4, (1, 3, 1, 8))
    """
    an = []
    pq = []

    i = 0
    p = 1
    a, q = opB(base, 0, p)
    an.append(a)
    assert p > 0
    assert q > 0
    while (p, q) not in pq:
        pq.append((p, q))
        try:
            a, p, q = step(base, p, q)
        except SQRTException:
            return a, tuple()
        an.append(a)
    return an[0], tuple(an[1:len(pq)+1])


if __name__ == '__main__':
    import doctest
    doctest.testmod()
