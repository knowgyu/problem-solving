import sys

input = sys.stdin.readline

N, S = map(int, input().split())
lst = list(map(int, input().split()))

p = [0] * (1 + N)
for i in range(1, N+1):
    p[i] = p[i - 1] + lst[i - 1]

l,r = 0,0
mn = int(1E7)
while r <= N:
    csm = p[r] - p[l]
    if csm >= S:
        mn = min(mn, r-l)
        l += 1
    else:
        r += 1

if mn == int(1E7):
    mn = 0
print(mn)