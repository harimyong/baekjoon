import sys
input=sys.stdin.readline
def bitmatch(x):    
    if visit[x]:
         return False
    visit[x]=True
    for nx in graph[x]:
        if select[nx]==-1 or bitmatch(select[nx]):
            select[nx]=x
            return True
    return False

n,m=map(int,input().split())

select=[-1 for _ in range(n+1)]
graph=[[] for _ in range(n+1)]
for _ in range(m):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1,n+1):
    visit=[False for _ in range(n+1)]
    bitmatch(i)

if -1 in select[1:]:
    print('Impossible')
else:
    for i in select[1:]:
        print(i)
    

   