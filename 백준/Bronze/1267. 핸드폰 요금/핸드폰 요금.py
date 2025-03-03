N=int(input())
lst = list(map(int,input().split()))

Y,M=0,0

for num in lst:
    Y += num//30 + 1
    M += num // 60 + 1

Y *= 10
M *= 15
if M<Y:
    print(f'M {M}')
elif M>Y:
    print(f'Y {Y}')
else:
    print(f'Y M {Y}')