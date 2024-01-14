n=int(input())
arr=list(map(int,input().split()))
ans=0

if n!=2:
    for i in range(1,n-1):
        tmp=arr[i-1:i+2]
        tmp.sort()
        ans=max(ans,tmp[1])
    print(ans)
else:
    print(min(arr))