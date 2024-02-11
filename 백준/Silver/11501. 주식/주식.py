import sys; input=sys.stdin.readline
t=int(input())
for _ in range(t):
    n=int(input())
    arr=list(map(int,input().split()))
    mx=0
    ans=0
    for i in range(n-1,-1,-1):
        if mx<arr[i]:
            mx=arr[i]
        else:
            ans+=mx-arr[i]
    print(ans)