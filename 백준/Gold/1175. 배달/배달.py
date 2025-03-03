import sys
from collections import deque

input = sys.stdin.readline

def bfs(case, q, visited):
    while q:
        ci, cj, to = q.popleft()
        if L[ci][cj] == "C":
            case.append((visited[ci][cj][to], ci, cj, to))
        for k in range(4):
            if k == to:  # 같은 방향으로 연속 이동 불가
                continue
            ni, nj = ci + di[k], cj + dj[k]
            if 0 <= ni < N and 0 <= nj < M and L[ni][nj] != "#" and visited[ni][nj][k] == 0:
                visited[ni][nj][k] = visited[ci][cj][to] + 1
                q.append((ni, nj, k))

def dfs(dist, startI, startJ, to, cnt):
    global ans
    if ans <= dist:
        return
    if cnt == 2:
        ans = min(ans, dist)
        return

    visited = [[[0] * 4 for _ in range(M)] for _ in range(N)]
    visited[startI][startJ][to] = dist
    q = deque([(startI, startJ, to)])
    case = []
    bfs(case, q, visited)

    for newDist, ni, nj, newTo in case:
        L[ni][nj] = "."
        dfs(newDist, ni, nj, newTo, cnt + 1)
        L[ni][nj] = "C"

N, M = map(int, input().split())
L = [list(input().strip()) for _ in range(N)]

di = [-1, 0, 1, 0]
dj = [0, 1, 0, -1]
INF = float('inf')

si = sj = -1
for i in range(N):
    for j in range(M):
        if L[i][j] == "S":
            si, sj = i, j
            break
    if si != -1:
        break

L[si][sj] = "."
ans = INF
for k in range(4):
    dfs(0, si, sj, k, 0)

if ans == INF:
    print(-1)
else:
    print(ans)
