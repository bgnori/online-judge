
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
    """
    assert p_npp > 0
    assert q_n >= 0
    for i in range(base):
        if base < pow(i * p_npp - q_n, 2):
            break
    a = i - 1
    return a, a * p_npp - q_n  #a_(n+1), q_(n+1)


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
    assert p_n, q_n > 0
    p_npp = opA(base, p_n, q_n)
    assert p_npp > 0
    a, q_npp = opB(base, q_n, p_npp)
    assert a, q_npp > 0
    return a, p_npp, q_npp

def cf(base):
    """
    >>> cf(2)
    (1,(2,))
    >>> cf(3)
    (1,(1,2))
    >>> cf(5)
    (2,(4,))
    >>> cf(6)
    (2,(2,4))
    >>> cf(23)
    (4,(1,3,1,8))
    """
    an = []
    pq = []

    i = 0
    p = 1
    a, q = opB(base, 0, p)
    an.append(a)
    pq.append((p, q))
    print a, p, q
    for i in range(6):
        p, q = pq[i]
        a, p, q = step(base, p, q)
        an.append(a)
        pq.append((p, q))
    print an, pq

    return 0

import doctest
doctest.testmod()
