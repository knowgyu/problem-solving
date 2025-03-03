S = int(input())

ans = 0
cnt = 0
for i in range(1,S):
    if ans + i > S:
        break
    ans += i
    cnt += 1

if S == 1:
    print(1)
else:
    print(cnt)