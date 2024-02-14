import sys; input=sys.stdin.readline
n=int(input())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
arr=[[B[i],A[i]] for i in range(n)]
arr.sort()
nowMax=0
preMax=arr[0][0]
ans=0
import math
for i in range(n):
    if preMax>arr[i][1]: #전의 구간에서 사용기간 최대값 > 현재 사용기간
        preMax=max(preMax,arr[i][0])
        cnt=math.ceil((preMax-arr[i][1])/30)
        arr[i][1]+=cnt*30
        ans+=cnt
    nowMax=max(nowMax,arr[i][1])
    if i+1<n and (arr[i][0]!=arr[i+1][0]):
        preMax=nowMax
print(ans)