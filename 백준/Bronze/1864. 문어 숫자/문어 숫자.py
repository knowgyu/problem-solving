while True:
    S = input().rstrip()
    if S == '#':
        break

    n = len(S)
    dct = {'-': 0, '\\': 1, '(': 2, '@': 3, '?': 4, '>': 5, '&': 6, '%': 7, '/': -1}

    ans = 0
    S = S[::-1]
    for i in range(n):
        ans += dct[S[i]] * (8**i)
    print(ans)
