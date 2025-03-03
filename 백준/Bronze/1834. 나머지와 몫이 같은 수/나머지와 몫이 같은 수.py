N = int(input())
alst = set()

for i in range(1,N):
    num = i + N*i
    alst.add(num)

print(sum(alst))