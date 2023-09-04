import sys
input=sys.stdin.readline
import heapq
pq=[]

class UnionFind:
    def __init__(self,n):
        self.house=[i for i in range(n+1)]
    
    def find(self,x):
        if self.house[x]==x:
            return x
        self.house[x]=self.find(self.house[x])
        return self.house[x]

    def merge(self,x,y):
        x,y=self.find(x),self.find(y)
        if x==y:
            return
        self.house[y]=x

n,m=map(int,input().split())
edge=[]

for _ in range(m):
    a,b,c=map(int,input().split())
    edge.append([c,a,b])

edge.sort()
cost,towns=0,0
u=UnionFind(n)

for c,a,b in edge:
    if u.find(a)!=u.find(b):
        u.merge(a,b)
        cost+=c
        towns+=1
        heapq.heappush(pq,-c)

    if towns==n-1:
        break

total=0
heapq.heappop(pq)
while pq:
    total+=(-heapq.heappop(pq))      
print(total)
