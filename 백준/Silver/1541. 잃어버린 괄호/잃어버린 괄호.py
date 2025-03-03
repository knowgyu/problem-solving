data = input().strip()
parts = data.split('-')


sm = sum(map(int, parts[0].split('+')))

for part in parts[1:]:
    sm -= sum(map(int, part.split('+')))

print(sm)
