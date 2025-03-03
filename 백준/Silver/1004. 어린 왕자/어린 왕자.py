import sys
input = sys.stdin.readline

def dist(x1, y1, x2, y2):
    return ((x1-x2)**2 + (y1-y2)**2)**0.5

def solve():
    x1, y1, x2, y2 = map(int, input().split())
    n = int(input())
    cnt = 0
    for _ in range(n):
        cx, cy, r = map(int, input().split())
        d1, d2 = dist(x1, y1, cx, cy), dist(x2, y2, cx, cy)
        if (d1 < r and d2 > r) or (d1 > r and d2 < r):
            cnt += 1
    print(cnt)

T = int(input())
for _ in range(T):
    solve()
