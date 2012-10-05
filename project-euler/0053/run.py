

class CombinationHelper:
    def __init__(self):
        self.memo = {0:1, 1:1}
        self.max_n = 1

    def fact(self, n):
        """
        >>> helper = CombinationHelper()
        >>> helper.fact(0)
        1
        >>> helper.fact(1)
        1
        >>> helper.memo.get(5, 0)
        0
        >>> helper.fact(5)
        120
        >>> helper.memo[5]
        120
        """
        if n in self.memo:
            return self.memo[n]
        p = 1
        for i in range(1, n+1):
            p *= i
        self.memo[n] = p
        return p

    def combination(self, n, r):
        """
        >>> helper = CombinationHelper()
        >>> helper.combination(5,3)
        10
        >>> helper.combination(23,10)
        1144066L
        """
        return self.fact(n)/(self.fact(r) * self.fact(n-r))

helper = CombinationHelper()
count = 0
for n in range(1, 101):
    for r in range(0, n+1):
        if helper.combination(n, r) > 1000000:
            count += 1
print count

#import doctest
#doctest.testmod()


