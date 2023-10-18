import sys
input=sys.stdin.readline
n=int(input())
arr=list(map(int,input().split()))
s=int(input())
cnt=s
ans=arr.copy()
ans.sort(reverse=True)

for i in range(n-1):
    if arr[i]==ans[i]:
        continue
    else:
        max_num=max(arr[i:min(n,i+cnt+1)])
        idx=arr.index(max_num)
      
        for j in range(idx,i,-1):
            arr[j],arr[j-1]=arr[j-1],arr[j]
        cnt-=(idx-i)

    if cnt<=0:
        break


print(*arr)