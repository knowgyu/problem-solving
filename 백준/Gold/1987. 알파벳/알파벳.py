import sys
input = sys.stdin.readline

def dfs(ci, cj, depth):
    global ans
    if depth + forprune <= ans:
        return

    ans = max(ans, depth)
    for di, dj in ((-1, 0), (1, 0), (0, -1), (0, 1)):
        ni, nj = ci + di, cj + dj
        if 0 <= ni < N and 0 <= nj < M and not visited[arr[ni][nj]]:
            visited[arr[ni][nj]] = True
            dfs(ni, nj, depth + 1)
            visited[arr[ni][nj]] = False

N, M = map(int, input().split())
arr = [list(map(lambda x: ord(x) - ord('A'), input().strip())) for _ in range(N)]
visited = [False] * 26

v = [0] * 26
for row in arr:
    for val in row:
        v[val] += 1

forprune = sum(1 for count in v if count > 0)

ans = 0
visited[arr[0][0]] = True
dfs(0, 0, 1)
print(ans)