import sys; input=sys.stdin.readline
n=int(input())
arr=[list(input().rstrip()) for _ in range(n)]
if n<=2:
    print(0)
    exit()
if n==3:
    if arr[0][0]=='1':
        print(1)
        exit()
    else:
        print(0)
        exit()
ans=0
dx=[-1,-1,-1,0,0,1,1,1]
dy=[-1,0,1,-1,1,-1,0,1]
for i in range(n):
    for j in range(n):
        flag=True
        if arr[i][j]=='#':
            for k in range(8):
                xx=dx[k]+i
                yy=dy[k]+j
                if arr[xx][yy]=='0':
                    flag=False
                    break
            if flag:
                for k in range(8):
                    xx=dx[k]+i
                    yy=dy[k]+j
                    if arr[xx][yy]!='#' and arr[xx][yy]!='*':
                        arr[xx][yy]=str(int(arr[xx][yy])-1)
                arr[i][j]='*'
                ans+=1
print(ans)
            
                