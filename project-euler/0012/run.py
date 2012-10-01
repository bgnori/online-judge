
class Prime:

    def __init__(self):
        self.primes = [2]
        self.count = 0
        self.pomp = self.prime_seq()

    def _isprime(self, k):
        assert k <= self.known_lagest()*self.known_lagest()
        for x in self.primes:
            if x*x > k:
                return True
            if not k % x:
                return False
        assert False

    def known_lagest(self):
        return self.primes[-1]

    def prime_seq(self):
        n = 3
        while True:
            if self._isprime(n):
                self.primes.append(n)
                self.count+=1
                yield self.known_lagest()
            n+=2
        assert False

    def extend(self, n):
        while self.known_lagest()*self.known_lagest() < n:
            self.pomp.next()

    def isprime(self, n):
        '''
        >>> p = Prime()
        >>> p.isprime(2)
        True
        >>> p.isprime(29)
        True
        >>> p.isprime(30)
        False
        >>> p.isprime(1000)
        False
        '''
        self.extend(n)
        return self._isprime(n)

    def decompose(self, n):
        '''
        >>> p = Prime()
        >>> p.decompose(60)
        [2, 2, 3, 5]
        >>> p.decompose(3)
        [3]
        '''
        self.extend(n)
        r = []
        for p in self.primes:
            d, m = divmod(n, p)
            while m == 0:
                n = d
                r.append(p)
                d, m = divmod(n, p)
        return r

    def divisors(self, n):
        '''
        >>> p = Prime()
        >>> p.divisors(28)
        set([1, 2, 4, 7, 14, 28])
        '''

        r = set()
        d = self.decompose(n)
        v = len(d)
        for i in range(pow(2, v)):
            mask = 1
            x = 1
            for j in range(v):
                if mask & i:
                    x *= d[j]
                mask *=2
            r.add(x)
        return r


def triangle(n):
    """
    >>> triangle(1)
    1
    >>> triangle(5)
    15
    >>> triangle(7)
    28
    >>> triangle(10)
    55
    """
    return n*(n+1)/2


p = Prime()
count = 0
i = 0
while count < 500:
    i += 1
    n = triangle(i)
    count = len(p.divisors(n))
print n

#import doctest
#doctest.testmod()


