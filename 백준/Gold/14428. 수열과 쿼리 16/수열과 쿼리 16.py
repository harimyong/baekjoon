import sys
input=sys.stdin.readline
n=int(input())
sys.setrecursionlimit(10**5)
arr=[0]+list(map(int,input().split()))

stree=[0 for _ in range(n*4)]

def init(left,right,node):
    if left==right:
        stree[node]=[arr[left],left]
        return stree[node]
    mid=(left+right)//2
    leftval=init(left,mid,node*2)
    rightval=init(mid+1,right,node*2+1)
    if leftval[0]<rightval[0]:
        stree[node]=leftval
    elif leftval[0]>rightval[0]:
        stree[node]=rightval
    else:
        if leftval[1]<rightval[1]:
            stree[node]=leftval
        else:
            stree[node]=rightval
    return stree[node]

INF=sys.maxsize
def find(start,end,left,right,node):
    if start>right or left>end:
        return [INF,INF]
    if start<=left and right<=end:
        return stree[node]
    mid=(left+right)//2
    leftval=find(start,end,left,mid,node*2)
    rightval=find(start,end,mid+1,right,node*2+1)
    # print(leftval,rightval)
    if leftval[0]<rightval[0]:
        return leftval
    elif leftval[0]>rightval[0]:
        return rightval
    else:
        if leftval[1]<rightval[1]:
            return leftval
        else:
            return rightval

def update(left,right,node,val,idx):
    if idx>right or left>idx:
        return stree[node]
    if left==right==idx:
        stree[node]=[val,idx]
        return stree[node]
    mid=(left+right)//2
    leftval=update(left,mid,node*2,val,idx)
    rightval=update(mid+1,right,node*2+1,val,idx)
    if leftval[0]<rightval[0]:
        stree[node]=leftval
    elif leftval[0]>rightval[0]:
        stree[node]=rightval
    else:
        if leftval[1]<rightval[1]:
            stree[node]=leftval
        else:
            stree[node]=rightval
    return stree[node]

init(1,n,1)
m=int(input())
for _ in range(m):
    c,a,b=map(int,input().split())
    if c==2:
        print(find(a,b,1,n,1)[1])
    else:
        update(1,n,1,b,a)
