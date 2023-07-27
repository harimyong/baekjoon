import sys
sys.setrecursionlimit(10 ** 6)

#input
n=int(input())
greed=[]
for i in range(n):
    s=input()
    greed.append(s)

dx=[1,-1,0,0]
dy=[0,0,1,-1]

#적록색약 O
visit_o=[]
for i in range(n):
    visit_o.append([0]*n)

def dfs_o(x,y,color):
    if color=='R' or color=='G':
        visit_o[x][y]=1
    else:
        visit_o[x][y]=2

    for i in range(4):
        xx=x+dx[i]
        yy=y+dy[i]
        if 0<=xx<n and 0<=yy<n:
            if visit_o[xx][yy]==0:
                if (color=='R' or color=='G') and (greed[xx][yy]=='R' or greed[xx][yy]=='G'): 
                    dfs_o(xx,yy,greed[xx][yy])
                elif (color=='B') and (greed[xx][yy]=='B'):
                    dfs_o(xx,yy,greed[xx][yy])
o=0
for i in range(n):
    for j in range(n):
        if visit_o[i][j]==0:
            dfs_o(i,j,greed[i][j])
            o+=1

#적록색약 x
visit_x=[]
for i in range(n):
    visit_x.append([0]*n)

def dfs_x(x,y,color):
    if color=='R':
        visit_x[x][y]=1
    elif color=='G':
        visit_x[x][y]=2
    else:
        visit_x[x][y]=3

    for i in range(4):
        xx=x+dx[i]
        yy=y+dy[i]
        if 0<=xx<n and 0<=yy<n:
            if visit_x[xx][yy]==0:
                if (color=='R') and (greed[xx][yy]=='R'): 
                    dfs_x(xx,yy,greed[xx][yy])
                elif (color=='B') and (greed[xx][yy]=='B'):
                    dfs_x(xx,yy,greed[xx][yy])
                elif (color=='G') and (greed[xx][yy]=='G'):
                    dfs_x(xx,yy,greed[xx][yy])
x=0
for i in range(n):
    for j in range(n):
        if visit_x[i][j]==0:
            dfs_x(i,j,greed[i][j])
            x+=1

print(x,o)