import sys
from itertools import combinations

input = sys.stdin.readline

N,K = map(int, input().split())
words = [input().rstrip() for _ in range(N)]

if K < 5:
    print(0)
else:
    ess = {'a', 'n', 't', 'i', 'c'}
    uniq = set()

    reduce = []
    for word in words:
        trimmed = set(word[4:-4]) - ess
        reduce.append(trimmed)
        uniq.update(trimmed)

    ans = 0

    for comb in combinations(uniq, min(K-5, len(uniq))):
        learned = set(comb) | ess
        readable_count = sum(1 for word in reduce if word <= learned)
        ans = max(ans, readable_count)

    print(ans)
