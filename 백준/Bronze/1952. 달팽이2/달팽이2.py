N,M= map(int, input().split())
arr = [[0] * M for _ in range(N)]

mx_cnt, cnt, flag, dr = 1, 0, 0, 1

ci, cj = 0,0
ei,ej = N//2+1,M//2
k = 1
# U R D L
di = [-1, 0, 1, 0]
dj = [0, 1, 0, -1]
ans = 0
while True:
    arr[ci][cj] = k
    if min(map(min,arr)) > 0:
        break
    cnt += 1
    ni, nj = ci + di[dr], cj + dj[dr]

    if 0<=ni<N and 0<=nj<M and arr[ni][nj] == 0:
        ci,cj = ni,nj
    else:
        dr = (dr+1)%4
        ci,cj = ci+di[dr],cj+dj[dr]
        ans += 1

    k+=1
print(ans)