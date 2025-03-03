import sys
input = sys.stdin.readline

N = int(input())
plst = []
for _ in range(N):
    x, y = map(int, input().split())
    plst.append((x, y))

ans = 0
for i in range(N):
    x1, y1 = plst[i]
    x2, y2 = plst[(i + 1) % N]
    ans += x1 * y2 - y1 * x2

ans = abs(ans) / 2.0
print(f'{ans:.1f}')
