import sys; input=sys.stdin.readline
from collections import deque
n,m=map(int,input().split())
arr=[list(map(int,input().split())) for _ in range(n)]

dx=[-1,1,0,0]
dy=[0,0,-1,1]
d=dict()


def counting(start,num):
    q=deque()
    q.append(start)
    cnt=0
    while q:
        x,y=q.popleft()
        if number_visit[x][y]:
            continue
        number_visit[x][y]=num
        cnt+=1
        for i in range(4):
            xx=x+dx[i]
            yy=y+dy[i]
            if 0<=xx<n and 0<=yy<m:
                if number_visit[xx][yy]==0 and arr[xx][yy]:
                    q.append((xx,yy))
    d[num]=cnt



# def numbering(start,number):
#         q=deque()
#         q.append(start)
#         while q:
#             x,y=q.popleft()
#             if number_visit[x][y]:
#                 continue
#             number_visit[x][y]=1
#             arr[x][y]=number
#             for i in range(4):
#                 xx=x+dx[i]
#                 yy=y+dy[i]
#                 if 0<=xx<n and 0<=yy<m:
#                     if number_visit[xx][yy]==0 and arr[xx][yy]:
#                         q.append((xx,yy))



num=1
number_visit=[[0 for _ in range(m)] for _ in range(n)]
for i in range(n):
    for j in range(m):
        if number_visit[i][j]==0 and arr[i][j]:
            counting((i,j),num)
            # for v in number_visit:
            #     print(*v)
           
            num+=1

ans=0
for i in range(n):
    for j in range(m):
        if number_visit[i][j]==0:
            sumlist=set()
            for idx in range(4):
                xx=i+dx[idx]
                yy=j+dy[idx]
                if 0<=xx<n and 0<=yy<m:
                    if number_visit[xx][yy]:
                        sumlist.add(number_visit[xx][yy])
            
            total=0
            for value in sumlist:
                total+=d[value]

            ans=max(ans,total+1)
print(ans)  