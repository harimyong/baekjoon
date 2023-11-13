import sys
from collections import deque
input=sys.stdin.readline

dx=[-1,1,0,0]
dy=[0,0,-1,1]


def numbering(i,j,number):
    q=deque()
    numbering_visit[i][j]=1
    zero_cnt[i][j]=number
    q.append((i,j))
    cnt=1
    while q:
        x,y=q.popleft()
        for i in range(4):
            xx=x+dx[i]
            yy=y+dy[i]
            if 0<=xx<n and 0<=yy<m:
                if numbering_visit[xx][yy]==0 and arr[xx][yy]==0:
                    zero_cnt[xx][yy]=number
                    numbering_visit[xx][yy]=1
                    cnt+=1
                    q.append((xx,yy))
    return cnt


def sum_zero(x,y):
    temp=set()
    for i in range(4):
        xx=x+dx[i]
        yy=y+dy[i]
        if 0<=xx<n and 0<=yy<m:
            if arr[xx][yy]==0:
                temp.add(zero_cnt[xx][yy])
    res=1
    for i in temp:
        res+=num_per_zero[int(i)]
        res%=10
    return res


n,m=map(int,input().split())
arr=[list(map(int, input().strip())) for _ in range(n)]
numbering_visit=[[0 for _ in range(m)] for _ in range(n)]
#numbering
num=1
num_per_zero = dict()
num_per_zero[0]=0
zero_cnt=[[0 for _ in range(m)] for _ in range(n)] 
for i in range(n):
    for j in range(m):
        if arr[i][j]==0 and zero_cnt[i][j]==0:
            zeros=numbering(i,j,num)
            num_per_zero[num]=int(zeros)
            num+=1





#sum_zero
for x in range(n):
    for y in range(m):
        if arr[x][y]==1:
            arr[x][y]=sum_zero(x,y)

for i in arr:
    print(''.join(list(map(str,i))))

