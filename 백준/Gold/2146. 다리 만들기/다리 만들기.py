from collections import deque

n = int(input())
city = [list(map(int,input().split())) for _ in range(n)]
start = []

land = [[False for _ in range(n)] for _ in range(n)]
for i in range(n):
    for j in range(n):
        if city[i][j] == 1:
            start.append([i,j])
queue = deque([start])    

def island(city,start,land,n):
    no = 1
    dx = [ 1,-1,0,0]
    dy = [0,0,1,-1]
    for nowStart in start:
        start_x = nowStart[1]
        start_y = nowStart[0]
        if land[start_y][start_x] == False:
            land[start_y][start_x] = [no,0]
            queue = deque([[start_y,start_x]])
            while queue:
                now = queue.popleft()
                now_x = now[1]
                now_y = now[0]
                for i in range(4):
                    new_x = now_x + dx[i]
                    new_y = now_y + dy[i]
                    if 0 <= new_x and new_x < n and 0 <= new_y and new_y < n:
                        if land[new_y][new_x] == False and city[new_y][new_x] == 1:
                            queue.append([new_y,new_x])
                            land[new_y][new_x] = [no,0]
            no += 1
island(city,start,land,n)

def whereIsAnotherIsland(land,queue,n):

    dx = [1,-1,0,0]
    dy = [0,0,1,-1]
    count = 1
    minimum = n*2

    while queue:
        nowQueue = queue.popleft()
        nextQueue = []
        for now in nowQueue:
            now_x = now[1]
            now_y = now[0]
            landNum = land[now_y][now_x][0]
            for i in range(4):
                new_x = now_x + dx[i]
                new_y = now_y + dy[i]
                if 0 <= new_x and new_x < n and 0 <= new_y and new_y < n:
                    if land[new_y][new_x] == False:
                        land[new_y][new_x] = [landNum,count]
                        nextQueue.append([new_y,new_x])
                    else:
                        if land[new_y][new_x][0] != land[now_y][now_x][0]:
                            minimum = min(minimum,land[new_y][new_x][1]+land[now_y][now_x][1])
        if nextQueue:
            queue.append(nextQueue)
            count += 1
    print(minimum)
whereIsAnotherIsland(land,queue,n)