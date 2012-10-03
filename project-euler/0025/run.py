

def fib():
    a = 0
    b = 1
    while True:
        yield b
        a, b = b, a+b

def take(n, enumer):
    for i in range(n):
        yield enumer.next()

def takeWhile(cond, enumer):
    x = enumer.next()
    while cond(x):
        yield x
        x = enumer.next()

def dropWhile(cond, enumer):
    x = enumer.next()
    while cond(x):
        x = enumer.next()
    yield x


en = fib()
n = 0
for i, x in enumerate(en):
    n = len(str(x))
    if n >= 1000:
        break
print i+1



