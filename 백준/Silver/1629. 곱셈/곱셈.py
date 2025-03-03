a, b, c = map(int, input().split())
ans = 1
base = a%c
while b > 0:
    if b%2==1:
        ans = (ans*base)%c
    base = (base*base)%c
    b//=2

print(ans)
