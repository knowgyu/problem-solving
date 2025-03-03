for _ in range(int(input())):
    n,m=map(int,input().split())
    tbl=[1]*31
    for i in range(2,31):
        tbl[i] = tbl[i-1]*i
    print(tbl[m]//(tbl[n] * tbl[m-n]))