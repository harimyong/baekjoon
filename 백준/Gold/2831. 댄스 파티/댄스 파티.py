import sys; input=sys.stdin.readline
n=int(input())
m=list(map(int,input().split()))
w=list(map(int,input().split()))
m.sort()
w.sort()
i=0
j=n-1
ans=0
while i<n and 0<=j:
    if m[i]<0 and w[j]>0 and abs(m[i])>w[j]:
        ans+=1
        i+=1
        j-=1
    elif m[i]<0 and w[j]>0 and abs(m[i])<=w[j]:
        j-=1
    elif m[i]>0 and w[j]<0 and m[i]<abs(w[j]):
        ans+=1
        i+=1
        j-=1
    elif m[i]>0 and w[j]<0 and m[i]>=abs(w[j]):
        j-=1
    elif m[i]<0 and w[j]<0:
        i+=1
    elif m[i]>0 and w[j]>0:
        j-=1
print(ans)