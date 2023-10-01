import sys; input=sys.stdin.readline
n,m=map(int,input().split())
arr=[list(str(input().rstrip())) for _ in range(n)]
visit=[0 for _ in range(26)]
Maxx=0
visit[ord(arr[0][0])-65]=1
def dfs(x,y,cost):
    global Maxx
    if cost>Maxx:
        Maxx=cost
    dx=[-1,1,0,0]
    dy=[0,0,-1,1]
    for i in range(4):
        xx=x+dx[i]
        yy=y+dy[i]
        if 0<=xx<n and 0<=yy<m:
            if visit[ord(arr[xx][yy])-65]==0:
                visit[ord(arr[xx][yy])-65]=1
                dfs(xx,yy,cost+1)
                visit[ord(arr[xx][yy])-65]=0
dfs(0,0,1)
print(Maxx) 