import sys
input=sys.stdin.readline
n=int(input())
sys.setrecursionlimit(10**5)
arr=[0]+list(map(int,input().split()))

stree=[0 for _ in range(n*4)]

def init(left,right,node):
    if left==right:
        if arr[left]%2==0:
            stree[node]=[1,0]
        else:
            stree[node]=[0,1]
        return stree[node]
    mid=(left+right)//2
    leftval=init(left,mid,node*2)
    rightval=init(mid+1,right,node*2+1)
    stree[node]=[leftval[0]+rightval[0],leftval[1]+rightval[1]]
    return stree[node]

INF=sys.maxsize
def find(start,end,left,right,node):
    if start>right or left>end:
        return [0,0]
    if start<=left and right<=end:
        return stree[node]
    mid=(left+right)//2
    leftval=find(start,end,left,mid,node*2)
    rightval=find(start,end,mid+1,right,node*2+1)
    return [leftval[0]+rightval[0],leftval[1]+rightval[1]]

def update(left,right,node,val,idx):
    if idx>right or left>idx:
        return stree[node]
    if left==right==idx:
        if val%2==0:
            stree[node]=[1,0]
        else:
            stree[node]=[0,1]
        return stree[node]
    mid=(left+right)//2
    leftval=update(left,mid,node*2,val,idx)
    rightval=update(mid+1,right,node*2+1,val,idx)
    stree[node]=[leftval[0]+rightval[0],leftval[1]+rightval[1]]
    return stree[node]

init(1,n,1)
m=int(input())
for _ in range(m):
    c,a,b=map(int,input().split())
    if c==1:
        update(1,n,1,b,a)
    else:
        print(find(a,b,1,n,1)[c-2])
    
