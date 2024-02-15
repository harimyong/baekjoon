import sys; input=sys.stdin.readline
n,k=map(int,input().split())
arr=list(map(int,input().split()))
ans=0
day=0
while True:
    flag=True
    for i in range(k,n):
        if arr[i-k]!=arr[i]:
            ans+=arr[i]-arr[i-k]
            arr[i]=arr[i-k]
            flag=False
            break
    arr.sort()
    if flag:
        print(ans,day)
        break
    day+=1
        