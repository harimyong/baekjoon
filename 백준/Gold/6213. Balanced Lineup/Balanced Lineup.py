import sys
sys.setrecursionlimit(10**8)
input=sys.stdin.readline
n,q=map(int,input().split())
arr=[0 for _ in range(n)]
for i in range(n):
    arr[i]=int(int(input()))
stree1=[0 for _ in range(n*4)] #max
stree2=[0 for _ in range(n*4)] #min
def init(left,right,node):
    if left==right:
        stree1[node]=arr[left]
        stree2[node]=arr[left]
        return [stree1[node],stree2[node]]
    
    mid=(left+right)//2
    leftval=init(left,mid,node*2)
    rightval=init(mid+1,right,node*2+1)
    stree1[node]=max(leftval[0],rightval[0])
    stree2[node]=min(leftval[1],rightval[1])
    return [stree1[node],stree2[node]]

def maxquery(start,end,left,right,node):
    if start>right or left>end:
        return 0
    if start<=left and right<=end:
        return stree1[node]
    mid=(left+right)//2
    leftval=maxquery(start,end,left,mid,node*2)
    rightval=maxquery(start,end,mid+1,right,node*2+1)
    return max(leftval,rightval)

def minquery(start,end,left,right,node):
    if start>right or left>end:
        return sys.maxsize
    if start<=left and right<=end:
        return stree2[node]
    mid=(left+right)//2
    leftval=minquery(start,end,left,mid,node*2)
    rightval=minquery(start,end,mid+1,right,node*2+1)
    return min(leftval,rightval)

init(0,n-1,1)
for _ in range(q):
    a,b=map(int,input().split())
    print(maxquery(a-1,b-1,0,n-1,1)-minquery(a-1,b-1,0,n-1,1))