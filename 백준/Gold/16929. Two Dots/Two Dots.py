import sys
input=sys.stdin.readline
from collections import deque

ans='No'
n,m=map(int,input().split())
arr=[list(input().rstrip()) for _ in range(n)]
visit=[[0 for _ in range(m)] for _ in range(n)]


def bfs(start):
    global ans
    q=deque()
    q.append(start)
    while q:
        x,y=q.popleft()
        if visit[x][y]:
            ans='Yes'
            break
        
        visit[x][y]=1
        dx=[-1,1,0,0]
        dy=[0,0,-1,1]
        for i in range(4):
            xx=x+dx[i]
            yy=y+dy[i]
            if 0<=xx<n and 0<=yy<m:
                if visit[xx][yy]==0 and arr[xx][yy]==arr[x][y]:
                    q.append((xx,yy))
        



for i in range(n):
    for j in range(m):
        if visit[i][j]==0:
            bfs((i,j))
            
print(ans)