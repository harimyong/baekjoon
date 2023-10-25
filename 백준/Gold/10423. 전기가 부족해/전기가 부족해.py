import sys
input=sys.stdin.readline
n,m,k=map(int,input().split())
powerplant=list(map(int,input().split()))
class unionfind:
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
    def getparent(self):
        return self.parent
    def powerplant(self,x):
        self.parent[x]=0

u=unionfind(n)
edge=[]
for _ in range(m):
    a,b,c=map(int,input().split())
    edge.append((c,a,b))
    if a in powerplant:
        u.powerplant(a)
    if b in powerplant:
        u.powerplant(b)
edge.sort()

dist=0
tot=0
for c,a,b in edge:
    if u.find(a)==u.find(b):
        continue
    
   
    u.merge(a,b)
    dist+=1
    tot+=c

    if dist==n-k:
        break
print(tot)
# print(u.getparent())