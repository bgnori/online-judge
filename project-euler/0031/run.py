


def biggest_coin(use):
    return use[:-1], use[-1]


def Try(amount, use):
    use, c = biggest_coin(use)
    if c > 1:
        count = amount/c
        s = 0
        for i in range(count+1):
            s += Try(amount - c*i, use)
        return s
    else:
        return 1

''' ((1, 5),) ((1, 3), (2, 1)), ((1, 1), (2, 2)), ((5,1),) '''
#print Try(5, [1, 2, 5])
print Try(200, [1, 2, 5, 10, 20, 50, 100, 200])





