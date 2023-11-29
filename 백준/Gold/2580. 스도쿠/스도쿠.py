import sys
input=sys.stdin.readline

arr=[list(map(int,input().split())) for _ in range(9)]
zeros=[]
for i in range(9):
    for j in range(9):
        if arr[i][j]==0:
            zeros.append((i,j))
def checkarea(x,y,k):
    startx=(x//3)*3
    starty=(y//3)*3
    for i in range(3):
        for j in range(3):
            #print(i,j)
            if arr[i+startx][j+starty]==k:
                return False
    return True

def checkrow(x,k):
    for i in range(0,9):
        if arr[x][i]==k:
            return False
    return True

def checkcol(y,k):
    for i in range(0,9):
        if arr[i][y]==k:
            return False
    return True

def back(idx):
    if idx==len(zeros):
        for i in range(9):
            print(*arr[i])
        exit(0)

    x,y=zeros[idx][0],zeros[idx][1]
    for i in range(1,10):
        if checkarea(x,y,i) and checkcol(y,i) and checkrow(x,i):
            arr[x][y]=i
            back(idx+1)
            arr[x][y]=0

back(0)