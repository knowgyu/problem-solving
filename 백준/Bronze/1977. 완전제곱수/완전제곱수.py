import math
m = int(input())
n = int(input())
alst = []
for i in range(m,n+1):
    a = math.sqrt(i)
    if a == int(a):
        alst.append(i)

if len(alst)>0:
    print(sum(alst))
    print(alst[0])
else:
    print(-1)