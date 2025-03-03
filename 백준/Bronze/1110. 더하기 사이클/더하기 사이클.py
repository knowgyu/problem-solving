n=int(input())

ans = 0
num = n
while True:
    if num<10:
        num = (num*10)+num
    else:
        tmp = (num//10) + (num%10)
        num = ((num%10)*10) + (tmp%10)

    ans += 1
    if num == n:
        break
print(ans)