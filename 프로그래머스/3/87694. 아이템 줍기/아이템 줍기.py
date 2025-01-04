def solution(rectangle, characterX, characterY, itemX, itemY):
    answer = 0
    from collections import deque
    q=deque()
    q.append((0,characterX*2,characterY*2))
    arr=[[0]*151 for _ in range(151)]
    for x1,y1,x2,y2 in rectangle:
        x1,y1,x2,y2=x1*2,y1*2,x2*2,y2*2
        for i in range(x1,x2+1):
            for j in range(y1,y2+1):
                arr[i][j]=1
    for x1,y1,x2,y2 in rectangle:
        x1,y1,x2,y2=x1*2,y1*2,x2*2,y2*2
        for i in range(x1+1,x2):
            for j in range(y1+1,y2):
                arr[i][j]=0
    dx=[-1,1,0,0]
    dy=[0,0,-1,1]
    while q:
        c,x,y=q.popleft()
        if (x,y)==(itemX*2,itemY*2):
            answer=c//2
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if 0<=nx<151 and 0<=ny<151:
                if arr[nx][ny]==1:
                    arr[nx][ny]=0
                    q.append((c+1,nx,ny))
    return answer