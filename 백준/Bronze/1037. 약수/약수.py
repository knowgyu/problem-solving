N = int(input())
lst = list(map(int, input().split()))
lst.sort()
if N%2==0:
    print(lst[0]*lst[-1])
else:
    M=N//2
    print(lst[M]**2)