from collections import deque

N = int(input())
lst = deque(range(1, N + 1))
ans = []
while len(lst) > 1:
    ans.append(lst.popleft())
    lst.append(lst.popleft())
if N == 1:print(1)
else:
    print(' '.join(map(str, ans)),end=' ')
    print(lst[0],end='')