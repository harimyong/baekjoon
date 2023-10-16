n,m,k=map(int,input().split())
arr=[0 for _ in range(n)]
for i in range(n):
    arr[i]=int(input().rstrip())

tree=[0 for _ in range(n*4)]

def init(node,left,right):
    if left==right:
        tree[node]=arr[left]
        return tree[node]
    mid=(left+right)//2
    left_val=init(node*2,left,mid)
    right_val=init(node*2+1,mid+1,right)
    tree[node]=left_val+right_val
    return tree[node]

init(1,0,n-1)

def query(start,end,left,right,node=1):
    if end<left or right<start:
        return 0
    if start<=left and right <= end:
        return tree[node]
    
    mid=(left+right)//2
    leftval=query(start,end,left,mid,node*2)
    rightval=query(start,end,mid+1,right,node*2+1)
    return leftval+rightval

def update(left,right,idx,val,node=1):
    if left>idx or idx>right:
        return tree[node]
    
    if left==right==idx:
        tree[node]=val
        return tree[node]
    
    mid=(left+right)//2
    leftval=update(left,mid,idx,val,node*2)
    rightval=update(mid+1,right,idx,val,node*2+1)
    tree[node]=leftval+rightval
    return tree[node]


for _ in range(m+k):
    a,b,c=map(int,input().split())
    if a==1:
        update(0,n-1,b-1,c)
    else:
        print(query(b-1,c-1,0,n-1))