import sys
input=sys.stdin.readline
q=[]
INF=10000000000
n,m=map(int,input().split())
edge=[[] for _ in range(n+1)]
dist=[INF for _ in range(n+1)]
dist[1]=0

for _ in range(m):
    a,b,c=map(int,input().split())
    edge[a].append([b,c])



for i in range(n):
    for cur in range(1,n+1):
        if dist[cur]==INF:
            continue
        for next,cost in edge[cur]:
            if dist[next]>cost+dist[cur]:
                dist[next]=cost+dist[cur]
                if i==n-1:
                    q.append(next)

if q!=[]:
    print(-1)

else:
    for i in range(2,len(dist)):
        if dist[i]==INF:
            print(-1)
        else:
            print(dist[i])