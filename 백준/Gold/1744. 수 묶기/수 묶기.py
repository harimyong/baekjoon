import sys; input=sys.stdin.readline
import heapq
minus=[]
plus=[]
n=int(input())
for _ in range(n):
    a=int(input())
    if a>0:
        heapq.heappush(plus,-a)
    else:
        heapq.heappush(minus,a)
plus.sort()
tmp=[]
while plus:

    a=-heapq.heappop(plus)
    if plus and plus[0]!=-1:
        b=-heapq.heappop(plus)
    else:
        b=1
    ret=a*b
    tmp.append(ret)

while minus:
    a=heapq.heappop(minus)
    if minus:
        b=heapq.heappop(minus)
    else:
        b=1
    ret=a*b
    tmp.append(ret)
    
print(sum(tmp))