import sys,heapq
input=sys.stdin.readline
INF=sys.maxsize

n,m=map(int,input().split())
graph=[[] for _ in range(n+1)]
parent=[[i for i in range(n+1)] for _ in range(n+1)]
for _ in range(m):
    a,b,c=map(int,input().split())
    graph[a].append((b,c))
    graph[b].append((a,c))

def djikstra(start):
    parent[start][start]='-'
    pq=[]
    heapq.heappush(pq,(0,start))
    dist=[INF for _ in range(n+1)]
    dist[start]=0
    temp=[]
    for next,nc in graph[start]:
        temp.append(next)
    while pq:
        cost,now=heapq.heappop(pq)
        if dist[now]<cost:
            continue
        for next,nc in graph[now]:
            before=dist[next]
            after=nc+cost
            if before>after:
                dist[next]=after
                if now!=start:
                    parent[start][next]=now
                heapq.heappush(pq,(after,next))
    def dfs(x):
        if parent[start][x]==x:
            return x
        parent[start][x]=dfs(parent[start][x])
        return parent[start][x]
    for i in range(1,n+1):
        if i!=start:
            dfs(i)


for i in range(1,n+1):
    djikstra(i)

for i in range(1,n+1):
    print(' '.join(list(map(str,parent[i][1:]))))


    