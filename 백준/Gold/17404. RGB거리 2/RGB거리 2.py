import sys; input=sys.stdin.readline
n=int(input())
arr=[]
INF=1e10
for i in range(n):
    a,b,c=map(int,input().split())
    arr.append([a,b,c])
ans=INF
for i in range(3):
    dp=[[INF,INF,INF] for _ in range(n)]
    dp[0][i]=arr[0][i]
    for j in range(1,n):
        dp[j][0]=min(dp[j-1][1],dp[j-1][2])+arr[j][0]    
        dp[j][1]=min(dp[j-1][2],dp[j-1][0])+arr[j][1]
        dp[j][2]=min(dp[j-1][1],dp[j-1][0])+arr[j][2]
    for j in range(3):
        if i!=j:
            ans=min(ans,dp[n-1][j])
print(ans)