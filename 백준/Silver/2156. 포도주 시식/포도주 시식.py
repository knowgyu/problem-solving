import sys
input = sys.stdin.readline
N = int(input())
lst = [0] + [int(input()) for _ in range(N)]

dp=[0]*(1+N)
if N==1: dp[1] = lst[1]
else:
    dp[1],dp[2] = lst[1],lst[1] + lst[2]
    for i in range(3,N+1):
        dp[i] = max(dp[i-1], dp[i-2]+lst[i], dp[i-3]+lst[i-1]+lst[i])

print(dp[N])