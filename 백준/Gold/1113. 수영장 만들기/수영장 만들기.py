from collections import deque

def bfs(si, sj, h):
    global ans

    q = deque()

    q.append((si, sj))
    flag = True
    v[si][sj] = True
    cnt = 1
    while q:
        ci, cj = q.popleft()

        for di,dj in ((-1,0),(1,0),(0,-1),(0,1)):
            nx = ci + di
            ny = cj + dj
            # 수영장 밖으로 물이 넘치면 flag False로 하고 연결된 나머지 전부 체크(수영장이 안되는 위치 전부)
            if nx == -1 or nx == N or ny == -1 or ny == M:
                flag = False
                continue

            if arr[nx][ny] <= h and not v[nx][ny]:
                v[nx][ny] = True
                q.append([nx, ny])
                cnt += 1
    if flag:
        ans += cnt

N, M = map(int, input().split())
arr = [list(map(int,input())) for _ in range(N)]

ans = 0
for num in range(1, 9):
    v = [[0] * M for _ in range(N)]
    for i in range(N):
        for j in range(M):
            if arr[i][j] <= num and not v[i][j]:
                bfs(i, j, num)

print(ans)