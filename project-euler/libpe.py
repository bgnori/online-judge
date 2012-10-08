
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


class SeqHolder:
    """
    >>> p = SeqHolder(lambda n: n*(3*n-1)/2)
    >>> 1 in p
    True
    >>> 35 in p
    True
    >>> 20 in p
    False
    >>> 100 in p
    False
    >>> 92 in p
    True
    >>> h = SeqHolder(lambda n: n*(2*n-1))
    >>> 1 in h
    True
    >>> 45 in h
    True
    >>> 44 in h
    False
    >>> t = SeqHolder(lambda n: n*(n+1)/2)
    >>> 40755 in t
    True
    >>> 40755 in h
    True
    >>> 40755 in p
    True

    """
    def __init__(self, f):
        self.max = 0
        self.memo = set()
        self.f = f

    def __contains__(self, k):
        if self.f(self.max) < k:
            self.extend(k)
        return k in self.memo

    def extend(self, k):
        v = self.f(self.max)
        while v < k:
            self.max += 1
            v = self.f(self.max)
            self.memo.add(v)


class _PrimeHelper:
    '''
    from 0021

    '''

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

    def pomp2nth(self, nth):
        while self.count < nth:
            self.pomp.next()

    def pomp2bound(self, bound):
        while self.known_lagest() < bound:
            self.pomp.next()

    def isprime(self, n):
        '''
        >>> p = _PrimeHelper()
        >>> p.isprime(2)
        True
        >>> p.isprime(29)
        True
        >>> p.isprime(30)
        False
        >>> p.isprime(1000)
        False
        '''
        if n == 1:
            return False
        self.extend(n)
        return self._isprime(n)

    def decompose(self, n):
        '''
        >>> p = _PrimeHelper()
        >>> p.decompose(60)
        [2, 2, 3, 5]
        >>> p.decompose(3)
        [3]
        >>> p.decompose(220)
        [2, 2, 5, 11]
        >>> p.decompose(284)
        [2, 2, 71]
        '''

        self.extend(n)
        r = []
        def foo(n, p):
            d, m = divmod(n, p)
            while m == 0:
                n = d
                r.append(p)
                d, m = divmod(n, p)
            return n, d==0

        for p in self.primes:
            n, flag = foo(n, p)
            if flag:
                break

        if n != 1:
            #fixd bug in 0012
            r.append(n)
        return r

    def divisors(self, n):
        '''
        >>> p = _PrimeHelper()
        >>> p.divisors(28)
        set([1, 2, 4, 7, 14, 28])
        '''

        r = set()
        d = self.decompose(n)
        v = len(d)
        for i in xrange(pow(2, v)):
            mask = 1
            x = 1
            for j in xrange(v):
                if mask & i:
                    x *= d[j]
                mask *=2
            r.add(x)
        return r

    def proper_divisors(self, n):
        '''
        >>> p = _PrimeHelper()
        >>> p.proper_divisors(28)
        set([1, 2, 4, 7, 14])
        >>> sorted(list(p.proper_divisors(220)))
        [1, 2, 4, 5, 10, 11, 20, 22, 44, 55, 110]
        '''
        s = self.divisors(n)
        s.remove(n)
        return s

    def d(self, n):
        '''
        >>> p = _PrimeHelper()
        >>> p.d(220)
        284
        >>> p.d(284)
        220
        '''
        return sum(self.proper_divisors(n)) 

    def amicable(self, n):
        '''
        >>> p = _PrimeHelper()
        >>> p.amicable(220)
        284
        >>> a = p.amicable(5)
        >>> print a
        None
        >>> a = p.amicable(6)
        >>> print a
        None
        '''
        candidate = self.d(n)
        if n == self.d(candidate) and not (candidate == n):
            return candidate
        return None


primehelper = _PrimeHelper()

if __name__ == '__main__':
    import doctest
    doctest.testmod()



