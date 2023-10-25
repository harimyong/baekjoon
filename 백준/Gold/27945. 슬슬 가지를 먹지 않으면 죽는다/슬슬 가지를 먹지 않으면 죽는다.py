import sys
input=sys.stdin.readline
n,m=map(int,input().split())

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

u=unionfind(n)
edge=[]
for _ in range(m):
    a,b,c=map(int,input().split())
    edge.append((c,a,b))

edge.sort()
cnt=1
dist=0
for c,a,b in edge:
    if u.find(a)==u.find(b):
        continue
    if cnt==c:
        cnt+=1
        dist+=1
        u.merge(a,b)

        if dist==n-1:
            break
    else:
        break
print(cnt)