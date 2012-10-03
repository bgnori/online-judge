


def gen(n):
    for a in range(2, n+1):
        for b in range(2, n+1):
            yield pow(a, b)

#print sorted(list(set(gen(5))))
#print len(sorted(list(set(gen(5)))))
print len(set(gen(100)))

