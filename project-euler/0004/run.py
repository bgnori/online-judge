




def palindrome(s):
    if not s:
        return True
    if len(s) == 1:
        return True
    if s[0] == s[-1]:
        return palindrome(s[1:-1])
    return False


largest = (0, 0, 0)
for i in range(100, 999):
    for j in range(100,999):
        if palindrome(str(i*j)) and largest[0] <i*j:
            largest = (i*j, i, j)
            print i,j, '=', i*j

