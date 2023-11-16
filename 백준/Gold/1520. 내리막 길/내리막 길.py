
import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**5)
n,m=map(int,input().split())
arr=[list(map(int,input().split())) for _ in range(n)]
dx=[-1,1,0,0]
dy=[0,0,-1,1]
dp=[[-1 for _ in range(m)] for _ in range(n)]


def dfs(x,y):
    if (x,y) == (n-1,m-1):
        return 1
    if dp[x][y]!=-1:
        return dp[x][y]

    cnt=0
    for i in range(4):
        xx=x+dx[i]
        yy=y+dy[i]
        if 0<=xx<n and 0<=yy<m:
            if arr[xx][yy]<arr[x][y]:
               cnt+=dfs(xx,yy)
    dp[x][y]=cnt
    return dp[x][y]

print(dfs(0,0))



