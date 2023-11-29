import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**5)
n,m=map(int,input().split())
arr=[list(input().rstrip()) for _ in range(n)]
visit=[0 for _ in range(n*m)]
dd={'U':[-1,0],'D':[1,0],'L':[0,-1],'R':[0,1]}
parent=[i for i in range(n*m)]

def find(x):
    if parent[x]==x:
        return x
    parent[x]=find(parent[x])
    return parent[x]

def merge(x,y):
    x,y=find(x),find(y)
    if x==y:
        return True
    if x>y:
        x,y=y,x
    parent[y]=x
    return False

tot=0
for x in range(n):
    for y in range(m):
        xx=dd[arr[x][y]][0]+x
        yy=dd[arr[x][y]][1]+y
        merge(x*m+y,xx*m+yy)

for i in range(n*m):
    if visit[find(i)]==0:
        visit[find(i)]=1
        tot+=1
print(tot)
