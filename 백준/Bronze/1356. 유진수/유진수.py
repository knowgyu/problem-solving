def solve(n):
    ln = len(n)

    if ln==1: return 'NO'

    i = 1
    while i < ln:
        l, r = 1, 1
        for c in n[:i]:
            l *= int(c)
        for c in n[i:]:
            r *= int(c)

        if l==r: return 'YES'
        i += 1

    else:
        return 'NO'

N=input()
print(solve(N))