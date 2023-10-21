import sys
input=sys.stdin.readline
from collections import deque

q=deque()
ans=0
n,m=map(int,input().split())
arr=[list(input().rstrip()) for _ in range(n)]
visit=[[0 for _ in range(m)] for _ in range(n)]

for i in range(n):
    for j in range(m):
        if arr[i][j]=='I':
            q.append((i,j))
            while q:
                x,y=q.popleft()
                if visit[x][y]:
                    continue
                if arr[x][y]=='P':
                    ans+=1
                visit[x][y]=1
                dx=[-1,1,0,0]
                dy=[0,0,-1,1]
                for k in range(4):
                    xx=dx[k]+x
                    yy=dy[k]+y
                    if 0<=xx<n and 0<=yy<m:
                        if visit[xx][yy]==0 and arr[xx][yy]!='X':
                            q.append((xx,yy))
if ans:
    print(ans)
else:
    print('TT')