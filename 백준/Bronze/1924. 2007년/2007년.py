x,y=map(int, input().split())

days = y
for i in range(1,x):
    if i in (1,3,5,7,8,10,12):
        days+=31
    elif i==2:
        days+=28
    else:
        days+=30

ans = days % 7
if ans == 1:
    print('MON')
elif ans == 2:
    print('TUE')
elif ans == 3:
    print('WED')
elif ans == 4:
    print('THU')
elif ans == 5:
    print('FRI')
elif ans == 6:
    print('SAT')
elif ans == 0:
    print('SUN')