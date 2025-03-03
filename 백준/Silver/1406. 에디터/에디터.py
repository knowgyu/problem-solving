import sys

input = sys.stdin.readline

s = input().rstrip()
left = list(s)  # 커서 왼쪽의 문자들
right = []  # 커서 오른쪽의 문자들 (역순)

M = int(input())

for _ in range(M):
    com = input().split()

    if com[0] == 'L':
        if left:
            right.append(left.pop())

    elif com[0] == 'D':
        if right:
            left.append(right.pop())

    elif com[0] == 'B':
        if left:
            left.pop()

    else:
        left.append(com[1])

print(''.join(left + right[::-1]))