import sys, heapq
input=sys.stdin.readline

#input
n=int(input())
graph=[[] for _ in range(n+1)]
indeg=[0 for _ in range(n+1)]
visit=[0 for _ in range(n+1)]
for i in range(1,n+1):
    a,b=map(int,input().split())
    graph[i].append(a)
    graph[i].append(b)
    indeg[a]+=1
    indeg[b]+=1

while True:
    pq=[]
    for i in range(1,n+1):
        if indeg[i]<2 and visit[i]==0:
            visit[i]=1
            heapq.heappush(pq,i)
    if pq==[]:
        break
    
    while pq:
        now = heapq.heappop(pq)
        indeg[graph[now][0]]-=1
        indeg[graph[now][1]]-=1
    


print(visit[1:].count(0))
for i in range(len(indeg[1:])+1):
    if indeg[i]==2:
        print(i,end=' ')
