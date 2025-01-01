import sys; input=sys.stdin.readline
import heapq
N,M,K=map(int,input().split())
graph=[[] for _ in range(N+1)]
for _ in range(M):
    a,b,cost=map(int,input().split())
    graph[a].append((b,cost))
    graph[b].append((a,cost))
dp=[[1e10 for _ in range(K+1)] for _ in range(N+1)]
pq=[]
heapq.heappush(pq,(0,1,0))
while pq:
    cost,now,k=heapq.heappop(pq)
    if dp[now][k]<cost: continue
    for next,next_cost in graph[now]:
        if cost+next_cost<dp[next][k]:
            dp[next][k]=cost+next_cost
            heapq.heappush(pq,(dp[next][k],next,k))
        if k<K:
            if cost<dp[next][k+1]:
                dp[next][k+1]=cost
                heapq.heappush(pq,(dp[next][k+1],next,k+1))
print(min(dp[N]))