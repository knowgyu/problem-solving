N, T, P = map(int, input().split())

if N > 0:
    lst = list(map(int, input().split()))
else:
    lst = []

lst.append(T)
lst.sort(reverse=True)

rank = lst.index(T) + 1

if N == P and lst[-1] == T:
    print(-1)
else:
    print(rank)
