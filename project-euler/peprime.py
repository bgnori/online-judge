
class Prime:
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
        if n == 1:
            return False
        self.extend(n)
        return self._isprime(n)

    def decompose(self, n):
        '''
        >>> p = Prime()
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
        for p in self.primes:
            d, m = divmod(n, p)
            while m == 0:
                n = d
                r.append(p)
                d, m = divmod(n, p)
        if n != 1:
            #fixd bug in 0012
            r.append(n)
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

    def proper_divisors(self, n):
        '''
        >>> p = Prime()
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
        >>> p = Prime()
        >>> p.d(220)
        284
        >>> p.d(284)
        220
        '''
        return sum(self.proper_divisors(n)) 

    def amicable(self, n):
        '''
        >>> p = Prime()
        >>> p.amicable(220)
        284
        >>> a = p.amicable(5)
        >>> print a
        None
        >>> a = p.amicable(6)
        >>> print a
        '''
        candidate = self.d(n)
        if n == self.d(candidate) and not (candidate == n):
            return candidate
        return None

