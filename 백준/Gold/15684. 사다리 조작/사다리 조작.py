def check():
    for sj in range(1, N+1):
        j = sj
        for i in range(1, H+1):
            if arr[i][j]==1:    # 오른쪽으로
                j+=1
            elif arr[i][j-1]==1:# 왼쪽으로
                j-=1
        if j!=sj:
            return False            # 하나라도 다르다면 실패
    return True

def dfs(n, s):
    global ans
    if ans==1:
        return

    if n==cnt:      # 모든 개수 선택
        if check():
            ans = 1
        return

    for j in range(s, CNT):
        ti,tj = pos[j]
        # 왼쪽도 사다리가 아니고, 오른쪽도 사다리가 아니면 가능!
        if arr[ti][tj-1]==0 and arr[ti][tj+1]==0:
            arr[ti][tj] = 1
            dfs(n+1, j+1)
            arr[ti][tj] = 0

N, M, H = map(int, input().split())

arr = [[0]*(N+2) for _ in range(H+1)]   # 좌,우 패딩
for _ in range(M):
    ti,tj = map(int, input().split())   # 사다리표시
    arr[ti][tj] = 1

pos = []
for i in range(1, H+1):
    for j in range(1, N+1):
        if arr[i][j]==0 and arr[i][j-1]==0 and arr[i][j+1]==0:
            pos.append((i,j))
CNT = len(pos)

# 추가하는 사다리개수 0~3
for cnt in range(4):
    ans = 0
    dfs(0,0)
    if ans==1:
        ans = cnt
        break
else:
    ans = -1
print(ans)