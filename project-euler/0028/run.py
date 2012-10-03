


def rt(n):
    return n*n

def lt(n):
    return rt(n) - (n-1)

def lb(n):
    return rt(n) - 2*(n-1)

def rb(n):
    return rt(n) - 3*(n-1)

def diagonal(n):
    s = 1
    for i in range(3, n+2, 2):
        s += (rt(i) + lt(i) +lb(i) + rb(i))
    return s

if False:
    print diagonal(1)
    print diagonal(3)
    print diagonal(5)
else:
    print diagonal(1001)

