import sys

input = sys.stdin.readline

moves = [(2, 1), (2, -1), (-2, 1), (-2, -1),(1, 2), (1, -2), (-1, 2), (-1, -2)]
def move(s, e):
    sc, sr = ord(s[0]) - ord('A'), int(s[1]) - 1
    ec, er = ord(e[0]) - ord('A'), int(e[1]) - 1
    for dc, dr in moves:
        if sc + dc == ec and sr + dr == er:
            return True
    return False


def solve(plans):
    if len(plans) != 36:
        return False

    visited = set()
    for pos in plans:
        if pos in visited:
            return False
        visited.add(pos)

    for i in range(1, len(plans)):
        if not move(plans[i - 1], plans[i]):
            return False

    if not move(plans[-1], plans[0]):
        return False

    return True

plans = [input().strip() for _ in range(36)]

if solve(plans):
    print("Valid")
else:
    print("Invalid")
