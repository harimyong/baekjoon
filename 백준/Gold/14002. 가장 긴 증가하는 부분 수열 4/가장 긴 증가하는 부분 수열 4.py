import sys
input=sys.stdin.readline
n=int(input())
arr=list(map(int,input().split()))
dp=[1 for _ in range(n)]
for i in range(1,n):
    for j in range(i):
        if arr[j]<arr[i]:
            dp[i]=max(dp[i],dp[j]+1)


order = max(dp)
print(order)
tmp = []
for i in range(n-1, -1, -1):
    if dp[i]==order:
        tmp.append(arr[i])
        order-=1
tmp.reverse()
print(*tmp)