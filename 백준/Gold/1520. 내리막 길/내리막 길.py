import sys

input = sys.stdin.readline
sys.setrecursionlimit(100000)


def dfs(i, j):
    if i == N - 1 and j == M - 1:  # 목표 지점에 도달했을 경우
        return 1

    if dp[i][j] != -1:  
        return dp[i][j]

    dp[i][j] = 0  # 초기화
    for di, dj in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
        ni, nj = i + di, j + dj
        if 0 <= ni < N and 0 <= nj < M and arr[i][j] > arr[ni][nj]:
            dp[i][j] += dfs(ni, nj)

    return dp[i][j]


N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

dp = [[-1] * M for _ in range(N)]

answer = dfs(0, 0)

print(answer)
