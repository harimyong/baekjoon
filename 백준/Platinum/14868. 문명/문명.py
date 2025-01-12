import sys; 
input=sys.stdin.readline
sys.setrecursionlimit(10**6)
from heapq import heappush as psh
from heapq import heappop as pp
from collections import deque
In,St,Ma,Di,q,INF=int,str,map,dict,deque(),sys.maxsize
def M_IS(type): return map(type,input().split()) 
def Inp_OnD(type): return list(M_IS(type)) #Set 1d list of a specific type
def Inp_TwD(type,N): return [list(M_IS(type)) for _ in range(N)] #Set 2d list of a specific type
def Inp_ThD(type,N,M): return [[list(M_IS(type)) for _ in range(M)] for _ in range(N)] #Set 3d list of a specific type
def Set_OnD(base,N): return [base for _ in range(N)] #Set 1d list with base
def Set_TwD(base,N,M): return [[base for _ in range(M)] for _ in range(N)] #Set 2d list with base
def Set_ThD(base,N,M,K): return [[[base for _ in range(K)] for _ in range(M)] for _ in range(N)] #Set 3d list with base
dx=[-1,1,0,0] # dx=[-1,0,1,-1,1,-1,0,1]
dy=[0,0,-1,1] # dy=[-1,-1,-1,0,0,1,1,1]
########################################################################################################################

def find(x):
    if parent[x]!=x: parent[x]=find(parent[x])
    return parent[x]

def merge(x,y):
    x,y=find(x),find(y)
    x,y=min(x,y),max(x,y)
    parent[y]=x

def combine():
    global K
    while civil:
        x,y=civil.popleft()
        for i in range(4):
            nx=dx[i]+x
            ny=dy[i]+y
            if 0<=nx<N and 0<=ny<N:
                if arr[nx][ny]!=0:
                    if arr[x][y]!=arr[nx][ny] and find(arr[x][y])!=find(arr[nx][ny]):
                        merge(arr[x][y],arr[nx][ny])
                        K-=1
        q.append((x,y))

def bfs():
    while q:
        x,y=q.popleft()
        for i in range(4):
            nx=dx[i]+x
            ny=dy[i]+y
            if 0<=nx<N and 0<=ny<N:
                if arr[nx][ny]==0:
                    arr[nx][ny]=arr[x][y]
                    civil.append((nx,ny))

N,K=M_IS(In)
arr=Set_TwD(0,N,N)
parent=[i for i in range(K+1)]
civil=deque()
q=deque()
for i in range(1,K+1):
    a,b=M_IS(In)
    arr[a-1][b-1]=i
    civil.append((a-1,b-1))

ans=0
while K>1:
    combine()
    if K==1: print(ans); exit()
    bfs()
    ans+=1