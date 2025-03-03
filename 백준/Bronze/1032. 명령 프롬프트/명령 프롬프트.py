N = int(input())
lst = [input().rstrip() for _ in range(N)]

if N == 1:
    ans = lst[0]
else:
    L = len(lst[0])
    ans = list(lst[0])

    for i in range(1,N):
        for j in range(L):
            if ans[j] != '?' and ans[j] != lst[i][j]:
                ans[j] = '?'

    ans = ''.join(ans)
print(ans)