import sys; input=sys.stdin.readline
n=int(input())
dp=[[0 for _ in range(2)] for _ in range(n+1)]
for i in range(1,n+1):
    if i%2==0:
        dp[i][0]=i//2
    if i%5==0:
        dp[i][1]=i//5

ans=1e10
if n%2==0:
    ans=n//2
if n%5==0:
    ans=n//5

for i in range(n,0,-1):
    if (n-dp[i][1]*5)%2==0 and dp[i][1]!=0:
        ans=min(ans,dp[i][1]+dp[n-i][0])
if ans!=1e10:
    print(ans)
else:
    print(-1)        