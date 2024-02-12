import sys; input=sys.stdin.readline
import heapq
n=int(input())
one=int(input())
pq=[]
for i in range(n-1):
    pq.append(-int(input()))
if n==1:
    print(0)
    exit()
heapq.heapify(pq)
ans=0
while -pq[0]>=one:
    a=-heapq.heappop(pq)
    ans+=1
    one+=1
    heapq.heappush(pq,-(a-1))
print(ans)