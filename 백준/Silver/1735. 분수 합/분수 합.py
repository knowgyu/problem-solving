import math
a1,a2=map(int, input().split())
b1,b2=map(int, input().split())
B = math.lcm(a2,b2)
A = a1 *(B//a2) + b1 * (B//b2)
c = math.gcd(A,B)
A//=c
B//=c
print(A,B)