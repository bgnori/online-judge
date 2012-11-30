

"""
 1900 Jan 1 is 1st day. 0th day is 1899 Dec 31.
 define "day1900" as follows:
    1900 Jan 1 is 1
    1900 Jan 31 is 31
    1900 Feb 1 is 32
    1900 Feb 28 is 59
    1901 Jan 1 is 366

 mod 7 == 1 <=> Monday
"""

def month2days(month, isleap):
    #        -   1   2   3   4   5   6   7   8   9  10  11  12
    usual = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    leap  = [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    if isleap:
        return leap[month]
    return usual[month]


def leaptest(year):
    """
    >>> leaptest(1900)
    False
    >>> leaptest(2000)
    True
    >>> leaptest(1904)
    True
    >>> leaptest(1903)
    False
    """
    if year % 4:
        return False
    elif year % 100 == 0:
        if year % 400:
            return False
        else:
            return True
    else:
        return True
    assert False


def day1900(year, month, day):
    """

    >>> day1900(1900, 1, 1)
    1
    >>> day1900(1900, 2, 28)
    59
    >>> day1900(1900, 3, 1)
    60
    >>> day1900(1901, 1, 1)
    366
    >>> day1900(1904, 1, 1) == 365 *4 + 1
    True
    >>> day1900(1904, 2, 1) == 365 *4 + 31 + 1
    True
    >>> day1900(1904, 2, 28) == 365 *4 + 31 + 28 
    True
    >>> day1900(1904, 2, 29) == 365 *4 + 31 + 29
    True
    >>> day1900(1904, 3, 1) == 365 *4 + 31 + 29 + 1
    True
    >>> day1900(1908, 3, 1) == 365 *8 + 1 + 31 + 29 + 1
    True
    """

    ys = 0
    for y in range(1900, year):
        if leaptest(y):
            ys += 366
        else:
            ys += 365

    leapy = leaptest(year)
    ms = sum([month2days(m, leapy) for m in range(1, month)])

    return ys + ms + day

count = 0
for y in range(1901, 2001):
    for m in range(1, 13):
        if(day1900(y, m, 1) % 7 == 0):
            count += 1

print count
