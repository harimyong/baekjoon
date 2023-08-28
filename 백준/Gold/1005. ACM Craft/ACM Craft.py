t=int(input())
from collections import deque
import sys
for _ in range(t):
    #input
    n,k=map(int,sys.stdin.readline().split())
    cost=[0]
    cost+=list(map(int,sys.stdin.readline().split()))
    graph=[[] for _ in range(n+1)]
    result=[0 for _ in range(n+1)]
    indeg=[0 for _ in range(n+1)]
    for _ in range(k):
        x,y=map(int,sys.stdin.readline().split())
        graph[x].append(y)
        indeg[y]+=1
    w=int(sys.stdin.readline())
    
    q=deque()
    for i in range(1,n+1):
        if indeg[i]==0:
            q.append(i)
            result[i]=cost[i]
    while indeg[w] > 0:
        cur = q.popleft()
        for next in graph[cur]:
            indeg[next] -= 1
            if indeg[next] == 0:
                q.append(next)
            result[next] = max(result[next], result[cur] + cost[next])
    print(result[w])
  
    
