


def foo(infile, outfile, n):
    mapping = {}
    for i in range(n):
        a, b = infile.readline().split()
        mapping[a]=b
    m = int(infile.readline())

    for j in xrange(m):
        x = infile.readline().split()[0]
        outfile.write(mapping.get(x, x))
    print >> outfile


def run(infile, outfile):
    while True:
        n = int(infile.readline())
        if n == 0:
            break
        foo(infile, outfile, n)


if __name__ == "__main__":
    import sys
    run(sys.stdin, sys.stdout)

