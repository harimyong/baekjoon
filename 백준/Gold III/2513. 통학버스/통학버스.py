import sys; input=sys.stdin.readline
n,k,s=map(int,input().split())
arr=[0]*100001
for _ in range(n):
    a,b=map(int,input().split())
    arr[a]=b
now=0
idx=-1
ans=0
for i in range(0,s):
    if arr[i] and idx==-1:
        idx=i
    if now+arr[i]<=k:
        now+=arr[i]
        arr[i]=0
    else:
        ans+=(s-idx)*2
        idx=i
        arr[i]-=k-now
        #print(ans,arr[i])
        if arr[i]!=0:
            now=0
            ans+=(arr[i]//k)*(s-i)*2
            arr[i]%=k
            #print(ans,arr[i])
            if arr[i]!=0:
                now+=arr[i]
                arr[i]=0
            else:
                idx=-1
    #print(now,idx)
if now:
    ans+=(s-idx)*2

now=0
idx=-1
for i in range(100000,s,-1):
    if arr[i] and idx==-1:
        idx=i
    if now+arr[i]<=k:
        now+=arr[i]
        arr[i]=0
    else:
        ans+=(idx-s)*2
        idx=i
        arr[i]-=k-now
        #print(ans,arr[i])
        if arr[i]!=0:
            now=0
            ans+=(arr[i]//k)*(i-s)*2
            arr[i]%=k
            #print(ans,arr[i])
            if arr[i]!=0:
                now+=arr[i]
                arr[i]=0
            else:
                idx=-1
    #print(now,idx)
if now:
    ans+=(idx-s)*2
print(ans)