import sys; input=sys.stdin.readline
n=int(input())
arr=[]
for _ in range(n):
    b,c=map(int,input().split())
    arr.append((b,c))
import heapq
pq=[]
arr.sort()
for a,b in arr:
    if pq and a>=pq[0]:
        heapq.heappop(pq)
    heapq.heappush(pq,b)
print(len(pq))