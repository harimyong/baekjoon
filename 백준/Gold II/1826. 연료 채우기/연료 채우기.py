import sys; input=sys.stdin.readline
n=int(input())
arr=[list(map(int,input().split())) for _ in range(n)]
L,P=map(int,input().split())
arr.append([L,0])
arr.sort()
import heapq
pq=[]
ans=0
for a,b in arr:
    if L<=P:
        break
    while P<a and pq:
        P+=-heapq.heappop(pq)
        ans+=1
    if P<a:
        break
    heapq.heappush(pq,-b)

if L>P:
    print(-1)
else:
    print(ans)