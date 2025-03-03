N=int(input())
a=0
for _ in range(N):
    s=input()
    if list(s) == sorted(s,key=s.find):
        a+=1
print(a)