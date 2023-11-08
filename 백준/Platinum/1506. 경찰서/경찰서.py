import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**5)


def SCC(G,V):
    label=[0]
    labels=[0 for _ in range(V+1)]
    visit=[False]*(V+1)
    ans,stack=[],[]

    def scc(cur):
        label[0]+=1
        parent=labels[cur]=label[0]
        stack.append(cur)

        for nx in G[cur]:
            if not labels[nx]:
                parent=min(parent,scc(nx))
            elif not visit[nx]:
                parent=min(parent,labels[nx])
        if parent==labels[cur]:
            cycle=[]
            while stack:
                top=stack.pop()
                cycle.append(cost[top-1])
                visit[top]=True
                if top==cur:
                    break
            ans.append(cycle)
        
        return parent
    
    for i in range(1,V+1):
        if not labels[i]:
            scc(i)

    for i in range(len(ans)):
        ans[i]=min(ans[i])


    return ans




V=int(input())
cost=list(map(int,input().split()))
graph=[list(map(int,list(input().rstrip())))for _ in range(V)]

G=[[] for _ in range(V+1)]
for i in range(V):
    for j in range(V):
        if graph[i][j]:
            G[i+1].append(j+1)

ans=SCC(G,V)
print(sum(ans))