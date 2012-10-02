
def digitsum(n):
    xs = str(n)
    s = 0
    for x in xs:
        s += int(x)
    return s


print digitsum(pow(2, 1000))

