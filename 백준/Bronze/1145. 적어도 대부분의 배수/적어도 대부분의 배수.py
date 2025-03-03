lst = list(map(int, input().split()))
v = [False]*5
tar = min(lst)
while 1:
    v = [tar%x == 0 for x in lst]
    if v.count(True) >= 3:
        break

    tar += 1

print(tar)