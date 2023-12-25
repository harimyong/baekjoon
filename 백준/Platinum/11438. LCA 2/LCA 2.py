import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**5)
n=int(input())
LOG=21
dp=[[0 for _ in range(LOG)] for _ in range(n+1)]
d=[0 for _ in range(n+1)]
visit=[0 for _ in range(n+1)]
graph=[[] for _ in range(n+1)]


for i in range(n-1):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

def dfs(x,depth):
    visit[x]=1
    d[x]=depth
    for i in graph[x]:
        if visit[i]==0:
            dp[i][0]=x
            dfs(i,depth+1)

def setparent():
    dfs(1,0)
    for i in range(1,LOG):
        for j in range(1,n+1):
            dp[j][i]=dp[dp[j][i-1]][i-1]


def lca(a,b):
    if d[a]>d[b]:
        a,b=b,a
    
    for i in range(LOG-1,-1,-1):
        if d[b]-d[a]>=(1<<i):
            b=dp[b][i]
    
    if a==b:
        return a
    
    for i in range(LOG-1,-1,-1):
        if dp[a][i]!=dp[b][i]:
            a=dp[a][i]
            b=dp[b][i]
    return dp[a][0]

setparent()
q=int(input())
for _ in range(q):
    a,b=map(int,input().split())
    print(lca(a,b))