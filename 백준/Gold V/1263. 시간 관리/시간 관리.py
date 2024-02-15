import sys; input=sys.stdin.readline
n=int(input())
arr=[list(map(int,input().split())) for _ in range(n)]
arr.sort(key=lambda x:x[1])
ans=-1
for time in range(arr[0][1]-arr[0][0]+1):
    ans=time
    for t,s in arr:
        time+=t
        if time>s:
            print(ans-1)
            exit()
print(ans)