import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**5)

def init(l,r,node):
    if l==r:
        stree[node]=[arr[l],0]
        return 
    mid=(l+r)//2
    init(l,mid,node*2)
    init(mid+1,r,node*2+1)
    temp=stree[node*2]+stree[node*2+1]
    temp.sort(reverse=True)
    stree[node]=[temp[0],temp[1]]
    
def update(l,r,idx,val,node):
    if l>idx or r<idx:
        return
    if l==r:
        stree[node]=[val,0]
        return
    mid=(l+r)//2
    update(l,mid,idx,val,node*2)
    update(mid+1,r,idx,val,node*2+1)
    temp=stree[node*2]+stree[node*2+1]
    temp.sort(reverse=True)
    stree[node]=[temp[0],temp[1]]
    
def query(s,e,l,r,node):
    if s>r or l>e:
        return [0,0]
    if s<=l and r<=e:
        return stree[node]
    mid=(l+r)//2
    temp=query(s,e,l,mid,node*2)+query(s,e,mid+1,r,node*2+1)
    temp.sort(reverse=True)
    return [temp[0],temp[1]]


n=int(input())
stree=[0 for _ in range(n*4)]
arr=[0]+list(map(int,input().split()))
m=int(input())
init(1,n,1)
for i in range(m):
    a,b,c=map(int,input().split())
    if a==1:
        update(1,n,b,c,1)
    else:
        res=query(b,c,1,n,1)
        res.sort(reverse=True)
        print(res[0]+res[1])