x, y, w, s = map(int, input().split())

mn = min(x, y)
mx = max(x, y)
rmoves = mx - mn

diag = mn * s + rmoves * w

stra = (x + y) * w

if (x + y) % 2 == 0:
    alldiag = mx * s
else:
    alldiag = (mx - 1) * s + w

ans = min(diag, stra, alldiag)

print(ans)
