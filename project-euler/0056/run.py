
print map(int, list(str(pow(3,10))))
print sum(map(int, list(str(pow(3,10)))))

m = 0
for a in range(1, 100):
    for b in range(1, 100):
        k = sum(map(int, list(str(pow(a,b)))))
        if k > m:
            m = k
            pair = (a, b)

print m, "with", pair


