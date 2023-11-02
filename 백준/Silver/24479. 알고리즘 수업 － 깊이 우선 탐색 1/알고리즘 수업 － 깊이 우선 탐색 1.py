import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**8)
n,m,r=map(int,input().split())
ans=[0 for _ in range(n+1)]
visit=[0 for _ in range(n+1)]
graph=[[] for _ in range(n+1)]
for _ in range(m):
    u,v=map(int,input().split())
    graph[u].append(v)
    graph[v].append(u)

for i in range(1,n+1):
    graph[i].sort()

cnt=1
def dfs(now):
    global cnt
    visit[now]=1
    ans[now]=cnt
    cnt+=1
    for i in graph[now]:
        if visit[i]==0:
            dfs(i)
dfs(r)

for i in range(1,n+1):
    print(ans[i])