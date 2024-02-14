import sys; input=sys.stdin.readline
n=int(input())
arr=list(map(int,input().split()))
arrow=[0]*1000001
ans=0
for i in arr:
    if arrow[i]==0:
        ans+=1
        arrow[i-1]+=1
    else:
        arrow[i]-=1
        arrow[i-1]+=1
print(ans)