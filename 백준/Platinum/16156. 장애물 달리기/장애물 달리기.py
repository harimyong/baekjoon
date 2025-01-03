import sys; input=sys.stdin.readline
from heapq import heappop as pop
from heapq import heappush as push
INF=sys.maxsize
dx=[-1,1,0,0]
dy=[0,0,-1,1]
def djik():
    dist=[[INF]*M for _ in range(N)]
    pq=[]
    for i in range(N):
        dist[i][M-1]=arr[i][M-1]
        push(pq,(arr[i][M-1],i,M-1,i))
    ans=[0]*N
    while pq:
        c,x,y,idx=pop(pq)
        if dist[x][y]<c: continue
        if y==0: ans[idx]+=1
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if 0<=nx<N and 0<=ny<M:
                if dist[nx][ny]>c+arr[nx][ny]:
                    dist[nx][ny]=c+arr[nx][ny]
                    push(pq,(dist[nx][ny],nx,ny,idx))
    return ans
N,M=map(int,input().split())
arr=[list(map(int,input().split())) for _ in range(N)] 
ans=djik()
for i in range(N): print(ans[i])