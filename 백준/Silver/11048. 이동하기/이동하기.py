import sys
input=sys.stdin.readline

n,m=map(int,input().split())
arr=[[0]+list(map(int,input().split())) for _ in range(n)]
arr.append([0 for _ in range(m+1)])
a,b=arr[-1],arr[0:len(arr)-1]
arr=[a]+b
dp=[[0 for _ in range(m+1)] for _ in range(n+1)]
for i in range(1,n+1):
    for j in range(1,m+1):
        dp[i][j]=max(arr[i][j]+dp[i-1][j-1],arr[i][j]+dp[i-1][j],arr[i][j]+dp[i][j-1])
print(dp[n][m])