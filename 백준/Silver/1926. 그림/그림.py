import sys
sys.setrecursionlimit(10**8)
n,m=map(int,input().split())
arr=[list(map(int,input().split())) for _ in range(n)]
visit=[[0 for _ in range(m)] for _ in range(n)]


def dfs(x,y):
    global g
    g+=1
    visit[x][y]=1
    dx=[-1,1,0,0]
    dy=[0,0,1,-1]
    
    for i in range(4):
        xx=x+dx[i]
        yy=y+dy[i]
        if 0<=xx<n and 0<=yy<m:
            if visit[xx][yy]==0:
                if arr[xx][yy]==1:
                    dfs(xx,yy)


cnt=0
M=0
for i in range(n):
    for j in range(m):
        if visit[i][j]==0 and arr[i][j]==1:
            g=0
            cnt+=1
            dfs(i,j)
            if M<g:
                M=g

print(cnt,M,sep='\n')