import sys; input=sys.stdin.readline
from collections import deque
n,m=map(int,input().split())
arr=[list(input().rstrip()) for _ in range(n)]

def dfs(x,y):
    arr[x][y]='x'
    dx=[-1,0,1]
    dy=[1,1,1]
    
    if y==m-1:
        return 1
    
    for i in range(3):
        xx=dx[i]+x
        yy=dy[i]+y
        if 0<=xx<n and 0<=yy<m:
            if arr[xx][yy]!='x':
                if dfs(xx,yy):
                    return 1
    return 0

ans=0
for i in range(n):
    ans+=dfs(i,0)
print(ans)