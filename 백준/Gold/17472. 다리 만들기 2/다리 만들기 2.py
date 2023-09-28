import sys
input=sys.stdin.readline

n,m=map(int,input().split())
arr=[list(map(int,input().split())) for _ in range(n)]
visit=[[0 for _ in range(m)] for _ in range(n)]

def numbering(x,y,now):
    visit[x][y]=1
    arr[x][y]=now
    
    dx=[1,-1,0,0]
    dy=[0,0,-1,1]

    for i in range(4):
        xx=x+dx[i]
        yy=y+dy[i]
        if 0<=xx<n and 0<=yy<m:
            if visit[xx][yy]==0 and arr[xx][yy]==1:
                numbering(xx,yy,now)

cnt=1    
for i in range(n):
    for j in range(m):
        if visit[i][j]==0 and arr[i][j]==1:
            numbering(i,j,cnt)
            cnt+=1
cnt-=1

edge=[]

def find_edge(x,y,now):
    from collections import deque
    q=deque()
    dx=[-1,1,0,0]
    dy=[0,0,-1,1]
    
    for i in range(4):
        q.append([x,y,now,i,0])

    while q:
        x,y,now,arrow,cost=q.popleft()
        if arr[x][y]!=0 and arr[x][y]!=now:
            a,b=now,arr[x][y]
            if a>b:
                a,b=b,a
            if [cost-1,a,b] not in edge and cost-1>=2:
                edge.append([cost-1,a,b])
            continue
        xx=x+dx[arrow]
        yy=y+dy[arrow]
        if 0<=xx<n and 0<=yy<m:
            if arr[xx][yy]!=now:
                q.append([xx,yy,now,arrow,cost+1])

for i in range(n):
    for j in range(m):
        if arr[i][j]!=0:
            find_edge(i,j,arr[i][j])


class UnionFind:
    def __init__(self,n):
        self.parent=[i for i in range(n+1)]
    
    def find(self,x):
        if self.parent[x]==x:
            return x
        self.parent[x]=self.find(self.parent[x])
        return self.parent[x]

    def merge(self,x,y):
        x,y=self.find(x),self.find(y)
        if x==y:
            return
        self.parent[y]=x

total,islands=0,0
edge.sort()
u=UnionFind(cnt)

for cost,a,b in edge:
    if u.find(a)==u.find(b):
        continue
    u.merge(a,b)
    total+=cost
    islands+=1
    if islands==cnt-1:
        break

if islands==cnt-1:
    print(total)
else:
    print(-1)
   
