import sys
input = sys.stdin.readline

data = input().rstrip()
ops = {'+': 1, '-': 1, '*': 2, '/': 2}
stk = []
out = []

for c in data:
    if c.isalpha():
        out.append(c)
    elif c == '(':
        stk.append(c)
    elif c == ')':
        while stk and stk[-1] != '(':
            out.append(stk.pop())
        stk.pop()
    else:
        while stk and stk[-1] != '(' and ops[stk[-1]] >= ops[c]:
            out.append(stk.pop())
        stk.append(c)

while stk:
    out.append(stk.pop())

print(''.join(out))
