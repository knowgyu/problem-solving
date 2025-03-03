import sys
input = sys.stdin.readline
def pre(node):
    if node == '.':
        return
    result.append(node)
    pre(tree[node][0])
    pre(tree[node][1])

def ino(node):
    if node == '.':
        return
    ino(tree[node][0])
    result.append(node)
    ino(tree[node][1])

def post(node):
    if node == '.':
        return
    post(tree[node][0])
    post(tree[node][1])
    result.append(node)

n = int(input())
tree = {}

# 트리 구조 생성
index = 1
for _ in range(n):
    r, l, rt = input().split()
    tree[r] = (l, rt)

result = []
pre('A')
print(''.join(result))

result = []
ino('A')
print(''.join(result))

result = []
post('A')
print(''.join(result))
