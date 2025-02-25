import math

w, h = map(int, input().split())
result = (w + h) - math.sqrt(w ** 2 + h ** 2)
if result.is_integer():
    print(int(result))
else:
    print(f"{result:.9f}")
