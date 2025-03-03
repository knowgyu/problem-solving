N = int(input())
alst = list(map(int, input().split()))
tbl = {}
for i in alst:
    tbl[i] = 1

M = int(input())
clst = list(map(int, input().split()))
for c in clst:
    try:
        print(tbl[c])
    except:
        print(0)
