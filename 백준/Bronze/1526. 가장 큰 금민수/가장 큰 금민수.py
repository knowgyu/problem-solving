N=int(input())
while True:
    for c in str(N):
        if c not in ('4', '7'):
            break
    else:
        print(N)
        break
    N-=1