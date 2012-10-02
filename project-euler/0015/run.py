

grid = {}

def getvalue(i, j):
    if i == 0 or j == 0:
        return 1
    return grid[(i,j)]

def setvalue(i, j, v):
    grid[(i,j)] = v


def foo(n):
    for i in range(1, n+1):
        for j in range(1, n+1):
            v = getvalue(i - 1, j) + getvalue(i, j - 1)
            setvalue(i, j, v)

foo(20)
print getvalue(20, 20)



