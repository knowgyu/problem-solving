N=int(input())

i = 1
while True:
    lb = i*(i-1) // 2
    ub = i*(i+1) // 2
    if lb < N <= ub:
        break
    i += 1

y = 1
x = i
while ub > N:
    y += 1
    x -= 1
    ub -= 1

if i%2 == 1:
    print(y, x, sep='/')
else:
    print(x, y, sep='/')
