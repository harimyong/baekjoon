import sys; input=sys.stdin.readline
dp=[[[0 for _ in range(3)] for _ in range(20)] for _ in range(20)]
dp[0][1][0]=1
n=int(input())
arr=[list(map(int,input().split())) for _ in range(n)]
for i in range(n):
    for j in range(n):
        if i+1<n and j+1<n and arr[i+1][j+1]==0 and arr[i][j+1]==0 and arr[i+1][j]==0:
            dp[i+1][j+1][2]+=dp[i][j][0]+dp[i][j][1]+dp[i][j][2]
        if j+1<n and arr[i][j+1]==0:
            dp[i][j+1][0]+=dp[i][j][0]+dp[i][j][2]
        if i+1<n and arr[i+1][j]==0:
            dp[i+1][j][1]+=dp[i][j][1]+dp[i][j][2]
print(sum(dp[n-1][n-1]))