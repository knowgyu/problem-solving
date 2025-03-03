a,b = input().split()
ans = 0
sm_a = 0
for i in a:
    sm_a += int(i)

for i in b:
    ans += sm_a * int(i)

print(ans)