import sys
input = sys.stdin.readline
# sys.stdin = open('input.txt', 'r')

N,M = map(int, input().split())
tbl = {}
rev = {}
for i in range(1,N+1):
    name = input().rstrip()
    tbl[name] = i
    rev[i] = name

for i in range(M):
    p = input().rstrip()
    if p.isdigit():
        print(rev[int(p)])
    else:
        print(tbl[p])
