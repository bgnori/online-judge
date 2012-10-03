
def digitsum(n):
    '''
    from 0016
    '''
    xs = str(n)
    s = 0
    for x in xs:
        s += int(x)
    return s

def fact(n):
    p = 1
    for i in range(1, n+1):
        p *= i
    return p

print fact(100)
print digitsum(fact(100))

