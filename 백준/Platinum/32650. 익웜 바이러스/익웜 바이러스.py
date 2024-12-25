import sys; input=sys.stdin.readline
import heapq

def find(node):
    if node!=parent[node]: parent[node]=find(parent[node])
    return parent[node]
    
def merge(x,y):
    x,y=find(x),find(y)
    if arr[x]<=arr[y]: 
        isVirus[y]=False
        isVirus[x]=True
        parent[y]=x
    else:
        isVirus[x]=False
        isVirus[y]=True
        parent[x]=y
        
N,M,K=map(int,input().split())
parent=[i for i in range(N+1)]
arr=[0]+list(map(int,input().split()))
isVirus=[True for _ in range(N+1)]
edge=[]
for i in range(M): 
    x,y,z=map(int,input().split())
    heapq.heappush(edge,(z-max(arr[x],arr[y]),z,x,y))
tot=sum(arr)
virusCnt=N
while edge:
    e=heapq.heappop(edge)
    v,cost,x,y=e
    xR,yR=find(x),find(y)
    if xR==yR:
        continue
    if xR!=x or yR!=y:
        heapq.heappush(edge,(cost-max(arr[xR],arr[yR]),cost,xR,yR))
    else:
        if virusCnt>K:
            merge(xR,yR)
            virusCnt-=1
            tot+=(cost-max(arr[xR],arr[yR]))
        else:
            if cost-max(arr[xR],arr[yR])<=0:
                merge(xR,yR)
                virusCnt-=1
                tot+=(cost-max(arr[xR],arr[yR]))          
if virusCnt>K: print(-1)
else: print(tot)     