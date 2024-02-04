import sys; input=sys.stdin.readline
from collections import deque
n,m,r=map(int,input().split())
graph=[[] for _ in range(n+1)]
for _ in range(m):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)
for i in range(1,n+1):
    graph[i].sort()
d=[-1]*(n+1)
t=[0]*(n+1)
order=1
q=deque()
q.append((r,0))
while q:
    now,depth=q.popleft()
    if t[now]:
        continue
    t[now]=order
    order+=1
    d[now]=depth
    for next in graph[now]:
        if t[next]==0:
            q.append((next,depth+1))
ans=0
for i in range(1,n+1):
    ans+=t[i]*d[i]
print(ans)