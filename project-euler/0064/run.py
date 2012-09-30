
def opA(base, rest, numerator):
    """
    >>> opA(23, 4, 1)
    (7, 1)
    >>> opA(23, 3, 7)
    (2, 7)
    >>> opA(23, 3, 2)
    (7, 2)
    >>> opA(23, 4, 7)
    (1, 7)
    """
    return (base - rest*rest )/ numerator, numerator

def opB(base, numerator, denominator):
    """
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
    for i in range(base):
        if base < pow(i * denominator - numerator, 2):
            break
    a = i - 1
    return a, a * denominator - numerator


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
    """
    an = []
    seen = set()

    i = 0
    denominator = 1
    numerator = 0
    for i in range(6):
        a, rest = opB(base, numerator, denominator)
        print denominator, numerator, a, rest
        denominator, numerator = opA(base, rest, denominator)
    return 0

import doctest 
doctest.testmod()
