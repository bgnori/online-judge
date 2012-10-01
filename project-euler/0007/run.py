

def test(k, xs):
    for x in xs:
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


s = prime_seq()
for i in range(10001):
    p = s.next()
print p

