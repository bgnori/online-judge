

def f(x):
    r = 0
    s = str(x)
    for c in s:
        r += pow(int(c), 5)
    return r

''' 9^5 = 59049'''
'''
>>> 6 * pow(9,5)
354294
'''


bound = 6 * pow(9,5)

s = 0
for i in range(2, bound+1):
    if f(i) == i:
        s += i
print s
