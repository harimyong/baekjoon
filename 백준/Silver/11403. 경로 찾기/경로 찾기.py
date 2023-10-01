import sys; input=sys.stdin.readline
from collections import deque
n=int(input())
arr=[list(map(int,input().split())) for _ in range(n)]
graph=[[] for _ in range(n)]
for i in range(n):
    for j in range(n):
        if arr[i][j]==1:
            graph[i].append(j)
def bfs(i):
    q=deque()
    visit=[0 for _ in range(n)]
    for nx in graph[i]:
        q.append((i,nx))
    while q:
        now,nx=q.popleft()
        visit[nx]=1
        for nxx in graph[nx]:
            if visit[nxx]==0:
                q.append((nx,nxx))
    return visit
visit=[]
for i in range(n):
    visit.append(bfs(i))
for i in visit:
    print(*i)