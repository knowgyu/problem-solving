def tmp(n):
    col = (n - 1) // 4
    row = (n - 1) % 4
    return col, row

a, b = map(int, input().split())
ca, ra = tmp(a)
cb, rb = tmp(b)
ans = abs(ca - cb) + abs(ra - rb)
print(ans)