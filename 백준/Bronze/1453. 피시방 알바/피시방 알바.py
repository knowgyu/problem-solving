n=int(input())
lst = list(map(int, input().split()))
print(len(lst) - len(set(lst)))