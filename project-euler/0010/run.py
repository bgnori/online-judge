
def test(k, xs):
    for x in xs:
        if x*x > k:
            return True
        if not k % x:
            return False
    return True


def prime_seq():
    primes = [2]
    head = 0
    n = 3
    while True:
        if test(n, primes):
            primes.append(n)
            yield primes[head]
            head+=1
        n+=2
    assert False


sum = 0
s = prime_seq()
p = s.next()
while p < 2000000:
    sum += p
    p = s.next()
print p
print sum

