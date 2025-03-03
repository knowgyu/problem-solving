import sys
input = sys.stdin.readline
while True:
    d = input().rstrip()
    if d =='0':
        break

    if d==d[::-1]:
        print('yes')
    else:
        print('no')