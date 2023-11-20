import sys
input=sys.stdin.readline
n,m,k=map(int,input().split())

arr=[list(map(int,list(input().rstrip())))for _ in range(n)]

from collections import deque
q=deque()
q.append((0,0,0))
visit=[[[0]*(k+1) for _ in range(m)] for _ in range(n)]
visit[0][0][0]=1
ans=sys.maxsize
while q:
    x,y,wall=q.popleft()
    dx=[-1,1,0,0]
    dy=[0,0,-1,1]
    if x == n-1 and y == m-1 :
        break
     
    for i in range(4):
        xx=x+dx[i]
        yy=y+dy[i]
        if 0<=xx<n and 0<=yy<m:
            if arr[xx][yy]==1 and wall<k and visit[xx][yy][wall+1]==0:
                visit[xx][yy][wall+1]=visit[x][y][wall]+1
                q.append((xx,yy,wall+1))
            elif arr[xx][yy]==0 and wall<=k and visit[xx][yy][wall]==0:
                visit[xx][yy][wall]=visit[x][y][wall]+1
                q.append((xx,yy,wall))

if max(visit[n-1][m-1])!=0:
    print(visit[n-1][m-1][wall])
else:
    print(-1)