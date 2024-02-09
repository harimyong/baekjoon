import sys; input=sys.stdin.readline
n=int(input())
graph=[[-1,-1] for _ in range(n+1)]
indeg=[0]*(n+1)

for _ in range(n):
    root,left,right=map(int,input().split())
    graph[root][0]=left
    graph[root][1]=right
    if left!=-1:
        indeg[left]+=1
    if right!=-1:
        indeg[right]+=1

level=[[1e10,0] for _ in range(n+1)]
width=[0] * (n+1)

cnt=0
def dfs(now,depth):
    if graph[now][0]!=-1:
        dfs(graph[now][0],depth+1)
    global cnt
    cnt+=1
    level[depth][0]=min(level[depth][0],cnt)
    level[depth][1]=max(level[depth][1],cnt)
    width[depth]=level[depth][1]-level[depth][0]+1
    if graph[now][1]!=-1:
        dfs(graph[now][1],depth+1)

for i in range(1,n+1):
    if indeg[i]==0:
        root=i
dfs(root,1)

idx=0
for i in range(1,n+1):
    if width[idx]<width[i]:
        idx=i
print(idx,width[idx])
