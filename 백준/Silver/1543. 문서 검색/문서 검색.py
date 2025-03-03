import sys
input = sys.stdin.readline
n = list(input().rstrip())
f = list(input().rstrip())
s = 0
t = len(n)
p = len(f)
v = [False] * t
cnt = 0
for i in range(0,t-p+1):
    if n[i:i+p] == f and v[i:i+p] == [False]*p:
        v[i:i+p] = [True]*p
        cnt += 1

print(cnt)