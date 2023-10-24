import sys
input=sys.stdin.readline
n,m=map(int,input().split())
man=list(map(int,input().split()))
woman=list(map(int,input().split()))
man.sort()
woman.sort()
dp=[[0 for _ in range(m+1)] for _ in range(n+1)]
for i in range(1,n+1):
    for j in range(1,m+1):
        if i==j:
            dp[i][j]=dp[i-1][j-1]+abs(man[i-1]-woman[j-1])
        elif i>j:
            dp[i][j]=min(dp[i-1][j-1]+abs(man[i-1]-woman[j-1]),dp[i-1][j])
        else:
            dp[i][j]=min(dp[i-1][j-1]+abs(man[i-1]-woman[j-1]),dp[i][j-1])
print(dp[n][m])