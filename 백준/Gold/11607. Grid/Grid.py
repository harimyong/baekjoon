import sys
sys.setrecursionlimit(10**5)
input=sys.stdin.readline
n,m=map(int,input().split())
arr=[list(map(int,input().rstrip()))for _ in range(n)]
visit=[[0 for _ in range(m)] for _ in range(n)]
from collections import deque
q=deque()
q.append((0,0,0))
cnt=sys.maxsize
while q:
    x,y,z=q.popleft()
    # print(x,y,z)
    if (x,y)==(n-1,m-1) and cnt>z:
        cnt=z
    if visit[x][y]:
        continue
    visit[x][y]=1
    dx=[-1,1,0,0]
    dy=[0,0,-1,1]
    for i in range(4):
        xx=x+(dx[i]*arr[x][y])
        yy=y+(dy[i]*arr[x][y])
        # print(xx,yy)
        if 0<=xx<n and 0<=yy<m:
            if visit[xx][yy]==0:
                q.append((xx,yy,z+1))
            
if sys.maxsize==cnt:
    print('IMPOSSIBLE')
else:
    print(cnt)