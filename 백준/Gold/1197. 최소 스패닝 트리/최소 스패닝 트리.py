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
        x,y=self.find(x),self.find(y)
        if x==y:
            return
        self.parent[y]=x

v,e=map(int,input().split())
u=UnionFind(v+1)
edge=[]
count,ans=0,0
for _ in range(e):
    a,b,c=map(int,input().split())
    edge.append([c,a,b])
edge.sort()

for cost,x,y in edge:
    if u.find(x)==u.find(y):
        continue
    ans+=cost
    u.merge(x,y)
    count+=1
    if count==v-1:
        break

print(ans)