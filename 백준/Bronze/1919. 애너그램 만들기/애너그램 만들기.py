from collections import Counter

w1 = input()
w2 = input()

c1 = Counter(w1)
c2 = Counter(w2)

remove = sum((c1 - c2).values()) + sum((c2 - c1).values())

print(remove)
