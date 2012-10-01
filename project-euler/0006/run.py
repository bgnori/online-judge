


def foo(n):
    sum = 0
    for i in xrange(n+1):
        sum += i*i
    return sum

def bar(n):
    sum = 0
    for i in xrange(n+1):
        sum += i
    return sum*sum

print bar(100) - foo (100)
