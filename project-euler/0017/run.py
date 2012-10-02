
spells = { 1:"one",
        2:"two",
        3:"three",
        4:"four",
        5:"five",
        6:"six",
        7:"seven",
        8:"eight",
        9:"nine",
        10:"ten",
        11:"eleven",
        12:"twelve",
        13:"thirteen",
        14:"thirteen",
        15:"fifteen",
        16:"sixteen",
        17:"seventeen",
        18:"eighteen",
        19:"nineteen",
        20:"twenty",
        30:"thirty",
        40:"forty",
        50:"fifty",
        60:"sixty",
        70:"seventy",
        80:"eighty",
        90:"ninety",
        100:"hundred",}

def inEnglish(n):
    r = []
    h, rest = divmod(n, 100)
    if h > 0:
        r.append(spells[h])
        r.append(spells[100])
        if rest:
            r.append("and")
    if rest:
        t, s = divmod(rest, 10)
        if t > 1:
            r.append(spells[t*10])
            if s:
                r.append(spells[s])
        else:
            r.append(spells[rest])
    return r

#print inEnglish(342)
#print inEnglish(115)

count = 0
for i in range(1000):
    s = ''.join(inEnglish(i))
    count += len(s)
count += len(''.join(['one', 'thousand']))
print count

