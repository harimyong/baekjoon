import sys
from collections import deque
input=sys.stdin.readline
n,m=map(int,input().split())
game=[i for i in range(101)]
for _ in range(n):
    a,b=map(int,input().split())
    game[a]=b
for _ in range(m):
    a,b=map(int,input().split())
    game[a]=b
visit=[False for _ in range(101)]
visit[1]=True
q=deque()
q.append((1,0))
while q:
    now,cost=q.popleft()
    if now==100:
        print(cost)
        break
    for i in range(1,7):
        next=now+i
        if 1<=next<=100:
            if visit[next]==False:
                if visit[next]==next:
                    visit[next]=True
                    q.append((next,cost+1))
                else:
                    visit[next]=True
                    visit[game[next]]=True
                    q.append((game[next],cost+1))