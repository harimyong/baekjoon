import sys
input=sys.stdin.readline

class UnionFind:
    def __init__(self,n):
        self.parent=[i for i in range(n+1)]
    
    def find(self,x):
        if self.parent[x]==x:
            return x
        self.parent[x]=self.find(self.parent[x])
        return self.parent[x]
    
    def merge(self,x,y):
        x,y = self.find(x),self.find(y)
        if x==y:
            return
        self.parent[y]=x



n=int(input())
m=int(input())

u=UnionFind(n+1)
for i in range(1,n+1):
    arr=[0]+list(map(int,input().split()))
    for j in range(1,len(arr)):
        if arr[j]==1:
            u.merge(i,j)

route=list(map(int,input().split()))
root=u.find(route[0])
flag=True
for i in route:
    if u.find(i)!=root:
        print('NO')
        flag=False
        break
if flag:
    print('YES')