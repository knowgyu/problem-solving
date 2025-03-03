N = int(input())
R = [input().strip() for _ in range(N)]

h_cnt = 0
v_cnt = 0

for row in R:
    e_cnt = 0
    for cell in row:
        if cell == '.':
            e_cnt += 1
        else:
            if e_cnt >= 2:
                h_cnt += 1
            e_cnt = 0
    if e_cnt >= 2:
        h_cnt += 1

for col in range(N):
    e_cnt = 0
    for row in range(N):
        if R[row][col] == '.':
            e_cnt += 1
        else:
            if e_cnt >= 2:
                v_cnt += 1
            e_cnt = 0
    if e_cnt >= 2:
        v_cnt += 1

print(h_cnt, v_cnt)
