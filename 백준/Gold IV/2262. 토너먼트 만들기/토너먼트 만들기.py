import sys; input=sys.stdin.readline
n=int(input())
arr=list(map(int,input().split()))+[0]
ans=0
for i in range(n,1,-1):
    for j in range(n):
        if arr[j]==i:
            ans+=(i-max(arr[j-1],arr[j+1]))
            for k in range(j,n):
                arr[k]=arr[k+1]
            n-=1
            break
print(ans)