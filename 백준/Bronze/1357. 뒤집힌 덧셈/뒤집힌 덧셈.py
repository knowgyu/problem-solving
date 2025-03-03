a,b=input().split()
ans = int(str(int(a[::-1]) + int(b[::-1]))[::-1])
print(ans)