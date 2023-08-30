import sys
input=sys.stdin.readline

class UnionFind:
    def __init__(self,n,arr):
        self.parent=[i for i in range(n+1)]
        self.cost=arr

    def find(self,x):
        if self.parent[x]==x:
            return x
        self.parent[x]=self.find(self.parent[x])
        return self.parent[x]
    
    def merge(self,x,y):
        x,y = self.find(x),self.find(y)
        if self.cost[x]>self.cost[y]:
            self.parent[x]=y
        else:
            self.parent[y]=x

  
                
n,m,k=map(int,input().split())
cost=[0]+list(map(int,input().split()))
u=UnionFind(n+1,cost)

for _ in range(m):
    x,y=map(int,input().split())
    u.merge(x,y)
    


visit=set()
total=0
flag=True
for i in range(1,n+1):
    if u.find(i) not in visit:
        total+=cost[u.find(i)]
        visit.add(u.find(i))
    if total>k:
        flag=False
        print('Oh no')
        break
if flag:
    print(total)