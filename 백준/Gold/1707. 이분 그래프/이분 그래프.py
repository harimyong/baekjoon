t=int(input())
import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**5)
for _ in range(t):
    v,e=map(int,input().split())
    visit=[0 for _ in range(v+1)]
    graph=[[] for _ in range(v+1)]
    for _ in range(e):
        a,b=map(int,input().split())
        graph[a].append(b)
        graph[b].append(a)
    
    def dfs(k,now):
        visit[now]=k
        for nx in graph[now]:
            if visit[nx]==0:                
                res= dfs(-k,nx)
                if not res:
                    return False
            else:
                if visit[nx]==k:
                    return False
        return True 
    
    for i in range(1,v+1):
        if visit[i]==0:
            res=dfs(1,i)
            if not res:
                break
    if res:
        print('YES')
    else:
        print('NO')