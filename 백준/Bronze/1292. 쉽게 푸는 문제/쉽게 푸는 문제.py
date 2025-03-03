l,r=map(int, input().split())

lst = []
for i in range(1,50):
    for _ in range(i):
        lst.append(i)

print(sum(lst[l-1:r]))