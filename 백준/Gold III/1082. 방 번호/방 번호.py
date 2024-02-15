import sys; input=sys.stdin.readline
n=int(input())
arr=list(map(int,input().split()))
m=int(input())
dp=[-1]*(m+1)
for i in range(n-1,-1,-1):
    for j in range(1,m+1):
        if j-arr[i]>=0:
            dp[j]=max(dp[j],i,dp[j-arr[i]]*10+i)
print(dp[m])