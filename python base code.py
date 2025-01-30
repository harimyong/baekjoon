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
S,E=((i,j) for i in range(N)for j in range(N)if G[i][j]=='#') # if G[i][j]=='#', Generate (i,j) and insert pair in S,E
########################################################################################################################
