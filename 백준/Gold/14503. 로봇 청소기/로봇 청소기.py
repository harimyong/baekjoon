n,m=map(int,input().split())
r,c,rd=map(int,input().split()) #rd 현재 방향 
arr=[list(map(int,input().split())) for _ in range(n)]
d=[0,1,2,3]
cnt=0
dx=[-1,0,1,0]
dy=[0,1,0,-1]
while True:
    if arr[r][c]==0:
        arr[r][c]=2
        cnt+=1

    flag=False
    for i in range(4):
        xx=dx[i]+r
        yy=dy[i]+c
        if 0<=xx<n and 0<=yy<m:
            if arr[xx][yy]==0:
                flag=True
                break
    
    #청소되지 않은 칸이 있는 경우
    if flag:
        rd=d[rd-1]
        xx=dx[rd]+r
        yy=dy[rd]+c
        if 0<=xx<n and 0<=yy<m:
            if arr[xx][yy]==0:
                r,c=xx,yy
    #없는 경우
    else:
        xx=dx[rd-2]+r
        yy=dy[rd-2]+c
        if 0<=xx<n and 0<=yy<m:
            if arr[xx][yy]==1:
                break
            else:
                r,c=xx,yy

print(cnt)