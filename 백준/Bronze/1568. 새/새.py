N = int(input())

ans = 0
n = 0
while N > 1:
    for i in range(1,N+1):
        if i * (i + 1) // 2 > N:
            n = i - 1
            break

    ans += n
    N -= n*(n+1)//2
if N == 1:
    ans += 1

print(ans)