import sys
from collections import deque

for _ in range(int(input())):
    def bfs(si,sj):
        q = deque()
        q.append((si, sj))
        v[si][sj] = 1

        while q:
            ci, cj = q.popleft()

            for di,dj in ((-1,0),(1,0),(0,-1),(0,1)):
                ni,nj=ci+di,cj+dj
                if 0<=ni<N and 0<=nj<M and v[ni][nj]==0 and arr[ni][nj]==1:
                    q.append((ni,nj))
                    v[ni][nj] = 1

        return 1


    N, M, K = map(int, input().split())
    arr = [[0] * M for _ in range(N)]
    v = [[0] * M for _ in range(N)]

    for _ in range(K):
        i,j = map(int, input().split())
        arr[i][j] = 1


    ans = 0
    for i in range(N):
        for j in range(M):
            if arr[i][j] == 1 and v[i][j] == 0:
                ans += bfs(i,j)

    print(ans)