import sys; input=sys.stdin.readline
n=int(input())
arr=[list(map(int,input().split())) for _ in range(n)]
arr.sort(key=lambda x:x[1],reverse=True)
ans=1e10
for d,t in arr:
    if ans>=t:
        ans=t-d
    else:
        ans-=d
print(ans)