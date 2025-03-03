import sys
input = sys.stdin.readline

N=int(input())
alst = list(map(int, input().split()))
blst = list(map(int, input().split()))

alst.sort()
blst.sort(reverse=True)

ans = 0
for i in range(N):
    ans += alst[i]*blst[i]

print(ans)