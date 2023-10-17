import sys;
sys.setrecursionlimit(10**5)
n,m=map(int,input().split())
arr=[0 for _ in range(n)]
for i in range(n):
    arr[i]=int(input())

stree=[0 for _ in range(n*4)]

def init(node,left,right):
    if left==right:
        stree[node]=[arr[left],arr[left]]
        return stree[node]
    mid=(left+right)//2
    leftval=init(node*2,left,mid)
    rightval=init(node*2+1,mid+1,right)
    stree[node]=[min(leftval+rightval),max(leftval+rightval)]
    return stree[node]

def query(node,start,end,left,right):
    if start>right or left>end:
        return []
    if start<=left and right<=end:
        return stree[node]
    mid=(left+right)//2
    leftval=query(node*2,start,end,left,mid)
    rightval=query(node*2+1,start,end,mid+1,right)
    return [min(leftval+rightval),max(leftval+rightval)]



init(1,0,n-1)
for _ in range(m):
    a,b=map(int,input().split())
    print(' '.join(list(map(str,query(1,a-1,b-1,0,n-1)))))