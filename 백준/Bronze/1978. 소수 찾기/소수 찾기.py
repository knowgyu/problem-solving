N = int(input())
lst = list(map(int, input().split()))
ans = 0
for i in range(len(lst)):
    if lst[i] == 1: continue
    for j in range(2,lst[i]):
        if lst[i]%j == 0: break
    else:
        ans += 1
print(ans)