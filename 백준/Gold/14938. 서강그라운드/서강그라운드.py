import sys,heapq
input=sys.stdin.readline
INF=sys.maxsize
n,m,r=map(int,input().split())
graph=[[] for _ in range(n+1)]
item=[0]+list(map(int,input().split()))
for _ in range(r):
    a,b,l=map(int,input().split())
    graph[a].append((b,l))
    graph[b].append((a,l))

def djikstra(start):
    dist=[INF for _ in range(n+1)]
    pq=[]
    dist[start]=0
    heapq.heappush(pq,(0,start))
    while pq:
        cost, now = heapq.heappop(pq)
        if dist[now]<cost:
            continue
        for next,nc in graph[now]:
            before=dist[next]
            after=cost+nc
            if before>after:
                dist[next]=after
                heapq.heappush(pq,(after,next))
    total=0
    for i in range(1,n+1):
        if dist[i]<=m:
           total+=item[i]
    return total
ans=0
for i in range(1,n+1):
    temp=djikstra(i)
    if ans<temp:
        ans=temp
print(ans)