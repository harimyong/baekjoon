import sys; input=sys.stdin.readline
t=int(input())
arr=[0]*(101)
arr[0],arr[1]=0,1
for i in range(2,101):
    arr[i]=arr[i-1]+arr[i-2]
for _ in range(t):
    n=int(input())
    ans=[]
    for i in range(100,0,-1):
        if n>=arr[i]:
            ans.append(arr[i])
            n-=arr[i]
    print(*ans[::-1])