import sys; input=sys.stdin.readline
import heapq
pq=[]
arr=[[] for _ in range(200001)]
n=int(input())
ans=0
for _ in range(n):
    a,b=map(int,input().split())
    arr[a].append(b)
for i in range(n,0,-1):
    for c in arr[i]:
        heapq.heappush(pq,-c)
    if pq:
        ans+=-pq[0]
        heapq.heappop(pq)
print(ans)