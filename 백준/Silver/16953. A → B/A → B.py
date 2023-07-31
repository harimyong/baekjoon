a,b=map(int,input().split())
from collections import deque
queue=deque([[a,1]])
INF=10000000000
minimum=INF
while queue:
    q=queue.pop()
    if q[0]==b:
        if q[1]<minimum:
            minimum=q[1]
    
    if q[0]*2<=b:
        queue.append([q[0]*2, q[1]+1])
    if (q[0]*10)+1<=b:
        queue.append([(q[0]*10)+1, q[1]+1])

if minimum!=INF:
    print(minimum)
else:
    print(-1)