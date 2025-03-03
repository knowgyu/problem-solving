N = int(input())
lst = list(map(int, input().split()))
M = max(lst)
for i in range(len(lst)):
    lst[i] = lst[i]/M*100
print(sum(lst)/N)