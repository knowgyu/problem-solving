N = int(input())
A = int(input())
arr = [[0] * N for _ in range(N)]

mx_cnt, cnt, flag, dr = 1, 0, 0, 0
M = N // 2
ci, cj = M, M

# U R D L
di = [-1, 0, 1, 0]
dj = [0, 1, 0, -1]
for k in range(1, N * N + 1):
    arr[ci][cj] = k
    if k == A:
        ai,aj = ci+1,cj+1
    cnt += 1
    ci, cj = ci + di[dr], cj + dj[dr]


    if cnt == mx_cnt:
        cnt = 0
        dr = (dr+1)%4

        if flag == 0:
            flag = 1
        else:
            flag = 0
            mx_cnt += 1

for l in arr:
    print(*l)
print(ai,aj)