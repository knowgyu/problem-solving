def fibonacci_count(n):
    cz = [0] * (n + 1)
    co = [0] * (n + 1)

    cz[0] = 1
    if n > 0:
        co[1] = 1

    for i in range(2, n + 1):
        cz[i] = cz[i - 1] + cz[i - 2]
        co[i] = co[i - 1] + co[i - 2]

    return cz[n], co[n]


T = int(input())
results = []
max_n = 0
queries = []

for _ in range(T):
    n = int(input())
    queries.append(n)
    max_n = max(max_n, n)

cz = [0] * (max_n + 1)
co = [0] * (max_n + 1)
cz[0] = 1
if max_n > 0:
    co[1] = 1
for i in range(2, max_n + 1):
    cz[i] = cz[i - 1] + cz[i - 2]
    co[i] = co[i - 1] + co[i - 2]

# 결과 출력
for n in queries:
    print(cz[n], co[n])
