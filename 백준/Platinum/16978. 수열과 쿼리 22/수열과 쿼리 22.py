import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**5)

def init(l,r,node):
    if l==r:
        stree[node]=arr[l]
        return 
    mid=(l+r)//2
    init(l,mid,node*2)
    init(mid+1,r,node*2+1)
    stree[node]=stree[node*2]+stree[node*2+1]
    
def update(l,r,idx,val,node):
    if l>idx or r<idx:
        return
    if l==r:
        stree[node]=val
        return
    mid=(l+r)//2
    update(l,mid,idx,val,node*2)
    update(mid+1,r,idx,val,node*2+1)
    stree[node]=stree[node*2]+stree[node*2+1]
    
def query(s,e,l,r,node):
    if s>r or l>e:
        return 0
    if s<=l and r<=e:
        return stree[node]
    mid=(l+r)//2
    return query(s,e,l,mid,node*2)+query(s,e,mid+1,r,node*2+1)


n=int(input())
stree=[0 for _ in range(n*4)]
arr=[0]+list(map(int,input().split()))
m=int(input())
init(1,n,1)
cq,sumq=[],[]
cqidx=1
for i in range(m):
    temp=list(map(int,input().split()))
    if temp[0]==1:
        b,c=temp[1],temp[2]
        cq.append((b,c))
        cqidx+=1
    else:
        a,b,c=temp[1],temp[2],temp[3]
        sumq.append((a,b,c,i+1))

res=[0 for _ in range(m+1)]
sumq.sort()

k=0
for i in range(len(sumq)):
    while sumq[i][0]>k:
        update(1,n,cq[k][0],cq[k][1],1)
        k+=1
    res[sumq[i][3]]=query(sumq[i][1],sumq[i][2],1,n,1)
for i in res:
    if i!=0:
        print(i)