import sys
input=sys.stdin.readline
tot=0
n=int(input())
arr=[0 for _ in range(10005)]
t=list(map(int,input().split()))
for i in range(n):
    arr[i]=t[i]

for i in range(n):

    if arr[i+1]>arr[i+2]:
        a=min(arr[i],arr[i+1]-arr[i+2])
        tot+=(a*5)
        arr[i]-=a
        arr[i+1]-=a

        b=min(arr[i],min(arr[i+1],arr[i+2]))
        tot+=(b*7)
        arr[i]-=b
        arr[i+1]-=b
        arr[i+2]-=b
    else:
        a=min(arr[i],min(arr[i+1],arr[i+2]))
        tot+=(a*7)
        arr[i]-=a
        arr[i+1]-=a
        arr[i+2]-=a


        b=min(arr[i],arr[i+1])
        tot+=(b*5)
        arr[i]-=b
        arr[i+1]-=b
    tot+=arr[i]*3

print(tot)
