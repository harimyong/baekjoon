def solution(maps):
    answer=0
    n=len(maps)
    m=len(maps[0])
    queue=[]
    
    #visit 배열에 maps 복사
    visit=maps.copy()
    queue.append([0,0,1])
    answer
    while queue!=[]:
        xy=queue[0]
        x=xy[0]
        y=xy[1]
        v=xy[2]
        visit[x][y]=0
        if x==n-1 and y==m-1:
            answer=v
            break
        dx=[-1,1,0,0]
        dy=[0,0,1,-1]
        for i in range(4):
            xx=x+dx[i]
            yy=y+dy[i]
            if 0<=xx<n and 0<=yy<m:
                if visit[xx][yy]==1:
                    visit[xx][yy]=0
                    queue.append([xx,yy,v+1])
        queue=queue[1:]
    if answer==0:
        answer-=1
    return answer