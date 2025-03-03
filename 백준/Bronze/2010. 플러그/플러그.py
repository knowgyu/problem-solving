N = int(input())
lst = [list(map(int, input().split())) for _ in range(N)]
ans = sum(map(sum,lst)) - len(lst) + 1
print(ans)