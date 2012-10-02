

f = open('0022/names.txt')

xs = []
for line in f:
    for s in line.split(','):
        name = s[1:-1]
        xs.append(name)
xs.sort()
#print xs
total = 0
for i, x in enumerate(xs):
    worth = 0
    for c in x:
        worth += (ord(c) - ord('A') + 1)
    #if x == 'COLIN':
    #    print worth
    total += ((i+1)*worth)
print total

