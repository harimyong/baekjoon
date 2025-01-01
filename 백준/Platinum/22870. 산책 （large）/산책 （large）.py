import sys; input=sys.stdin.readline
import heapq
INF=sys.maxsize

def djik(st):
    dist=[INF]*(N+1)
    dist[st]=0
    pq=[]
    heapq.heappush(pq,(0,st))
    while pq:
        c,now=heapq.heappop(pq)
        if dist[now]<c: continue
        for nx,nc in graph[now]:
            if used[nx]: continue
            if nc+c<dist[nx]:
                dist[nx]=nc+c
                heapq.heappush(pq,(nc+c,nx))
    return dist

def erase(x,dist):
    from collections import deque
    q=deque()
    q.append(e)
    while q:
        now=q.popleft()
        for nx,nc in graph[now]:
            if dist[now]-dist[nx]==nc and now<parent[nx]:
                parent[nx]=now
                q.append(nx)
    x=s
    while x!=e:
        x=parent[x]
        used[x]=True
    used[s]=used[e]=False
    
N,M=map(int,input().split())
parent=[INF]*(N+1)
graph=[[] for _ in range(N+1)]
used=[False]*(N+1)
for _ in range(M):
    a,b,c=map(int,input().split())
    graph[a].append((b,c))
    graph[b].append((a,c))
s,e=map(int,input().split())
for i in range(N+1): graph[i].sort()
dist1=djik(s)
erase(e,dist1)
dist2=djik(e)
print(dist1[e]+dist2[s])