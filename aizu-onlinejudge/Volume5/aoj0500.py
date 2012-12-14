





def foo(infile, outfile, n):
    ax = 0
    bx = 0
    for i in range(n):
        a, b = infile.readline().split()
        a = int(a)
        b = int(b)
        if a > b:
            ax += (a + b)
        elif a < b:
            bx += (a + b)
        elif a == b:
            ax += a
            bx += b
        else:
            assert False
    print >> outfile, ax, bx


def run(infile, outfile):
    while True:
        n = int(infile.readline())
        if n == 0:
            break
        foo(infile, outfile, n)


if __name__ == "__main__":
    import sys
    run(sys.stdin, sys.stdout)
