n=[list(map(int,input().split())) for _ in range(5)]
import sys
sys.setrecursionlimit(10**8)
answer=[]
def dfs(x,y,num):
    global answer
    if len(num)==6:
        answer.append(int(num))
        return
    dx=[-1,1,0,0]
    dy=[0,0,1,-1]
    for i in range(4):
        xx=x+dx[i]
        yy=y+dy[i]
        if 0<=xx<5 and 0<=yy<5:
            dfs(xx,yy,num+str(n[xx][yy]))

for i in range(5):
    for j in range(5):
        dfs(i,j,'')
answer.sort()
answer=set(answer)
print(len(answer))