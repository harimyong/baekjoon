import sys
input=sys.stdin.readline
n,k=map(int,input().split())
dp=[[0 for _ in range(k+1)] for _ in range(n+1)]

arr=[[0,0]]

for _ in range(n):
    arr.append(list(map(int,input().split())))

for i in range(1,n+1):
    for j in range(1,k+1):
        wei,val=arr[i][0],arr[i][1]

        if j<wei:
            dp[i][j]=dp[i-1][j]
        else:
            dp[i][j]=max(val+dp[i-1][j-wei],dp[i-1][j])

print(dp[n][k])