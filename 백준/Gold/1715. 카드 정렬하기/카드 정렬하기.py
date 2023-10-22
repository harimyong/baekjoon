import sys; input=sys.stdin.readline
import heapq
pq=[]
n=int(input())
total=0
for _ in range(n):
    heapq.heappush(pq,int(input()))
while pq:
    a=heapq.heappop(pq)
    if pq:
        b=heapq.heappop(pq)
    else:
        print(total)
        break
    total+=a+b
    heapq.heappush(pq,a+b)