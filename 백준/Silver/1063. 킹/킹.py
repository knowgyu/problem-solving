def is_valid(pos):
    r, c = pos
    return 1 <= r <= 8 and ord('A') <= c <= ord('H')

def move_piece(kng, stn, dr, moves):
    di, dj = moves[dr]
    new_king = (kng[0] + di, kng[1] + dj)

    if not is_valid(new_king):
        return kng, stn

    if new_king == stn:
        new_stone = (stn[0] + di, stn[1] + dj)
        if is_valid(new_stone):
            return new_king, new_stone
        else:
            return kng, stn
    return new_king, stn

K, S, N = input().split()
N = int(N)
kng = (int(K[1]), ord(K[0]))
stn = (int(S[1]), ord(S[0]))
moves = {'R':(0,1), 'L':(0,-1), 'B':(-1,0), 'T':(1,0), 'RT':(1,1), 'LT':(1,-1), 'RB':(-1,1), 'LB':(-1,-1)}

for _ in range(N):
    move = input().strip()
    kng, stn = move_piece(kng, stn, move, moves)

print(chr(kng[1]) + str(kng[0]))
print(chr(stn[1]) + str(stn[0]))
