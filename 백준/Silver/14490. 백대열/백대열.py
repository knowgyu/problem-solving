from math import gcd

a,b = map(int,input().split(':'))
g = gcd(a,b)

A = int(a/g)
B = int(b/g)
print(f'{A}:{B}')