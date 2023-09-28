import sys
from collections import deque
input=sys.stdin.readline

r,c,t=map(int,input().split())
arr=[list(map(int,input().split())) for _ in range(r)]

dx=[0,1,0,-1]
dy=[1,0,-1,0]

def mv(li,temp,ran,value):
    if value=='y':
        if ran[0]<ran[1]:
            for i in ran:
                li[i],li[i+1],temp=li[i]-temp,li[i+1]+temp,li[i+1]
            
        else:
            for i in ran:
                li[i],li[i-1],temp=li[i]-temp,li[i-1]+temp,li[i-1]

    if value=='x':
        if ran[0]<ran[1]: #밑으로
            if li[0][0]==-1:
                for i in ran:
                    li[i][c-1],li[i+1][c-1],temp=li[i][c-1]-temp,li[i+1][c-1]+temp,li[i+1][c-1]
            if li[len(li)-1][0]==-1:
                for i in ran:
                    if li[i+1][0]!=-1:
                        li[i][0],li[i+1][0],temp=li[i][0]-temp,li[i+1][0]+temp,li[i+1][0]
                    else:
                        li[i][0]=li[i][0]-temp                
        
        else:    #위로
            if li[0][0]==-1:
                for i in ran:
                    if li[i-1][0]!=-1:
                        li[i][0],li[i-1][0],temp=li[i][0]-temp,li[i-1][0]+temp,li[i-1][0]
                    else:
                        li[i][0]=li[i][0]-temp
            if li[len(li)-1][0]==-1:
                for i in ran:
                    li[i][c-1],li[i-1][c-1],temp=li[i][c-1]-temp,li[i-1][c-1]+temp,li[i-1][c-1]
    
    return li,temp


for i in range(0,r):
    if arr[i][0]==-1:
        up=i
        down=i+1
        break

for _ in range(t):
    q=deque()
    for i in range(r):
        for j in range(c):
            if arr[i][j]>=5:
                q.append((i,j,arr[i][j]))

    while q:
        x,y,val=q.popleft()
        temp=int(val/5)
        for i in range(4):
            xx=x+dx[i]
            yy=y+dy[i]
            if 0<=xx<r and 0<=yy<c:
                if arr[xx][yy]!=-1:
                    arr[xx][yy]+=temp
                    arr[x][y]-=temp
    
    
    a_arr=arr[:up+1]
    a_arr[-1],temp=mv(a_arr[-1],a_arr[-1][1],range(1,c-1),'y')
    a_arr,temp=mv(a_arr,temp,range(len(a_arr)-1,0,-1),'x')
    a_arr[0],temp=mv(a_arr[0],temp,range(c-1,0,-1),'y')
    a_arr,temp=mv(a_arr,temp,range(0,len(a_arr)-1),'x')
    
    b_arr=arr[down:]
    b_arr[0],temp=mv(b_arr[0],b_arr[0][1],range(1,c-1),'y')
    b_arr,temp=mv(b_arr,temp,range(0,len(b_arr)-1),'x')
    b_arr[-1],temp=mv(b_arr[-1],temp,range(c-1,0,-1),'y')
    b_arr,temp=mv(b_arr,temp,range(len(b_arr)-1,0,-1),'x')
    
    arr=a_arr+b_arr

total=0
for i in arr:
    total+=sum(i)
print(total+2)
    