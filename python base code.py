import sys; input=sys.stdin.readline
from heapq import heappush as psh
from heapq import heappop as pp
from collections import deque
In,St,Ma,Di=int,str,map,dict
def M_IS(type): return map(type,input().split()) 
def Inp_OnD(type): return list(M_IS(type)) #Set 1d list of a specific type
def Inp_TwD(type,N): return [list(M_IS(type)) for _ in range(N)] #Set 2d list of a specific type
def Inp_ThD(type,N,M): return [[list(M_IS(type)) for _ in range(M)] for _ in range(N)] #Set 3d list of a specific type
def Set_OnD(base,N): return [base for _ in range(N)] #Set 1d list with base
def Set_TwD(base,N,M): return [[base for _ in range(M)] for _ in range(N)] #Set 2d list with base
