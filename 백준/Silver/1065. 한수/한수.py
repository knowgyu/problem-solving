n=int(input())
dp=[0]*1001

for i in range(1,100):
    dp[i]=i

for i in range(100,1001):
    h = i//100
    t = (i-h*100)//10
    o = i%10

    if o-t == t-h or h-t == t-o:
        dp[i] = dp[i-1] + 1
    else:
        dp[i] = dp[i-1]

print(dp[n])