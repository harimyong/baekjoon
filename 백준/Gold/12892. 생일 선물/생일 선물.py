import sys; input=sys.stdin.readline
arr=[]
n,d=map(int,input().split())
for _ in range(n):
    p,v=map(int,input().split())
    arr.append((p,v))
arr.sort()
left,right=0,0
ans=arr[0][1]
tot=arr[0][1]
for i in range(1,n):
    right=i
    tot+=arr[i][1]
    while arr[right][0]-arr[left][0]>=d:
        tot-=arr[left][1]
        left+=1
    ans=max(ans,tot)
print(ans)