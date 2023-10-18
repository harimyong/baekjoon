n=int(input())
import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**5)

parent=[0 for i in range(n+1)]
def leveling(x):
    visit[x]=1
    for nx in graph[x]:
       if visit[nx]==0:
           level[nx]=level[x]+1
           parent[nx]=x
           leveling(nx)

def find(a,b):
    while level[a]!=level[b]:
        if level[a]>level[b]:
            a=parent[a]
        else:
            b=parent[b]
    while a!=b:
        a=parent[a]
        b=parent[b]
    return a

graph=[[] for _ in range(n+1)]
for _ in range(n-1):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

visit=[0 for _ in range(n+1)]
level=[0 for _ in range(n+1)]
leveling(1)

m=int(input())
for _ in range(m):
    a,b=map(int,input().split())
    print(find(a,b))