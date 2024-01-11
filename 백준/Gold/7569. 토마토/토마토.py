import sys
from collections import deque

n,m,h=map(int,input().split())
graph=[[list(map(int,input().split())) for _ in range(m)] for _ in range(h)]
q=deque()
for i in range(h):
    for j in range(m):
        for k in range(n):
            if graph[i][j][k]==1: 
                q.append((i,j,k,0))
ans=0
while q:
    x,y,z,day=q.popleft()
    if day>ans:
        ans=day
    dx=[-1,1,0,0,0,0]
    dy=[0,0,-1,1,0,0]
    dz=[0,0,0,0,-1,1]
    for i in range(6):
        xx=x+dx[i]
        yy=y+dy[i]
        zz=z+dz[i]
        if 0<=xx<h and 0<=yy<m and 0<=zz<n:
            if graph[xx][yy][zz]==0:
                graph[xx][yy][zz]=1
                q.append((xx,yy,zz,day+1))

cnt=0
for i in range(h):
    for j in range(m):
        cnt+=graph[i][j].count(0)

if cnt==0:
    print(ans)
else:
    print(-1)
