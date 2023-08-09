n=int(input())
arr=[[1,1] for _ in range(n+1)]
m=int(input())
import sys
for _ in range(m):
    x,y=map(int,sys.stdin.readline().rstrip().split())
    for i in range(x,y+1):
        if i==x:
            arr[i][1]=0
        elif i>x and i<y:
            arr[i][0],arr[i][1]=0,0
        else:
            arr[i][0]=0
answer=0
flag=False
for i in arr[1:]:
    if flag==False and i[0]==1 and i[1]==1:
        answer+=1
    elif flag==False and i[0]==1 and i[1]==0:
        flag=True
    elif flag==True and i[0]==0 and i[1]==1:
        flag=False
        answer+=1

print(answer)