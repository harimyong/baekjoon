import sys,heapq
input=sys.stdin.readline
INF=sys.maxsize
n,m=map(int,input().split())
graph=[[] for _ in range(n+1)]
for _ in range(m):
    a,b,c=map(int,input().split())
    graph[a].append((b,c))
    graph[b].append((a,c))

pq=[]
dist=[INF for _ in range(n+1)]
dist[1]=0
heapq.heappush(pq,(0,1))
while pq:
    cost, now = heapq.heappop(pq)
    if dist[now]<cost:
        continue
    for next,nc in graph[now]:
        before=dist[next]
        after=nc+cost
        if before>after:
            dist[next]=after
            heapq.heappush(pq,(after,next))

print(dist[n])