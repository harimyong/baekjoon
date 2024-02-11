import sys; input=sys.stdin.readline
n,m=map(int,input().split())
arr=list(map(int,input().split()))
import heapq
heapq.heapify(arr)
for _ in range(m):
    x=heapq.heappop(arr)
    y=heapq.heappop(arr)
    heapq.heappush(arr,x+y)
    heapq.heappush(arr,x+y)
print(sum(arr))