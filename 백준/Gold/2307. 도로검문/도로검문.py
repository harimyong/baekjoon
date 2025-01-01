import sys; input=sys.stdin.readline
import heapq
INF=sys.maxsize

def djik(a,b,flag):
    dist=[INF]*(N+1)
    dist[1]=0
    pq=[]
    heapq.heappush(pq,(0,1))
    while pq:
        c,now=heapq.heappop(pq)
        if dist[now]<c: continue
        for nx,nc in graph[now]:
            if (now,nx) in ((a,b),(b,a)): continue
            if nc+c < dist[nx]:
                if flag: parent[nx]=now
                dist[nx]=nc+c
                heapq.heappush(pq,(nc+c,nx))
    return dist[N]

N,M=map(int,input().split())
parent=[-1 for i in range(N+1)]
graph=[[] for _ in range(N+1)]
for _ in range(M):
    a,b,c=map(int,input().split())
    graph[a].append((b,c))
    graph[b].append((a,c))
    
res=djik(-1,-1,True)
ans=0
x=N
while parent[x]!=-1:
    a,b=x,parent[x]
    res2=djik(a,b,False)
    if res2==INF: print(-1); exit()
    else: ans=max(ans,res2-res)
    x=parent[x]
print(ans)    
