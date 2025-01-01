import sys; input=sys.stdin.readline
import heapq
INF=sys.maxsize

def djik(flag):
    dist=[INF]*(N+1)
    if flag: st=1
    else: st=N
    dist[st]=0
    pq=[]
    heapq.heappush(pq,(0,st))
    while pq:
        c,now=heapq.heappop(pq)
        if dist[now]<c: continue
        for nx,nc in graph[now]:
            if nc+c<dist[nx] and height[now]<height[nx]:
                dist[nx]=nc+c
                heapq.heappush(pq,(nc+c,nx))
    return dist

N,M,D,E=map(int,input().split())
height=[0]+list(map(int,input().split()))
graph=[[] for _ in range(N+1)]
for _ in range(M):
    a,b,c=map(int,input().split())
    graph[a].append((b,c))
    graph[b].append((a,c))
up=djik(True)
down=djik(False)
ans=-INF
for i in range(1,N+1):
    if INF in (up[i],down[i]): continue
    ans=max(ans,E*height[i]-(up[i]+down[i])*D)    
print(ans if ans!=-INF else 'Impossible')