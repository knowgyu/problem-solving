from collections import deque
N,K=map(int, input().split())

q = deque(list(range(1,N+1)))
alst = []
while q:
    q.rotate(-(K-1))
    c = q.popleft()
    alst.append(c)
print('<' + ', '.join(map(str, alst)) + '>')