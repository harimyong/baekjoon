import sys; input=sys.stdin.readline
n=int(input())
arr=list(map(int,input().split()))
dp=[[0 for _ in range(n)] for _ in range(n)]

for i in range(0,n):
    dp[i][i]=1

for i in range(0,n-1):
    if arr[i]==arr[i+1]:
        dp[i][i+1]=1

for i in range(n-1,-1,-1):
    for j in range(i+2,n):
        if arr[i]==arr[j] and dp[i+1][j-1]:
            dp[i][j]=1

t=int(input())
for _ in range(t):
    a,b=map(int,input().split())
    print(dp[a-1][b-1])