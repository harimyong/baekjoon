import sys; input=sys.stdin.readline
import heapq
INF=sys.maxsize

N,M,K=map(int,input().split())
graph=[[] for _ in range(N+1)]
for _ in range(M):
    a,b,c=map(int,input().split())
    graph[a].append((b,c))

pq=[]
dist=[[] for _ in range(N+1)]
heapq.heappush(pq,(0,1))
heapq.heappush(dist[1],0)
while pq:
    c,now=heapq.heappop(pq)
    for nx,nc in graph[now]:
        ncost=nc+c
        if len(dist[nx])<K:
            heapq.heappush(dist[nx],-ncost)
            heapq.heappush(pq,(ncost,nx))
        elif ncost < -dist[nx][0]:
            heapq.heappop(dist[nx])
            heapq.heappush(dist[nx],-ncost)
            heapq.heappush(pq,(ncost,nx))
for i in range(1,N+1):
    if len(dist[i])==K: print(-dist[i][0])
    else: print(-1)