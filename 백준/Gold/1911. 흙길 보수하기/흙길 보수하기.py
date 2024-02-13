import sys; input=sys.stdin.readline
n,l=map(int,input().split())
arr=[]
for i in range(n):
    a,b=map(int,input().split())
    arr.append((a,b))
arr.sort()
ans=0
right=0
for a,b in arr:
    if right<a:
        ans+=(b-a)//l
        if (b-a)%l==0:
            right=b
        else:
            ans+=1
            right=a+((b-a)//l*l)+l
    elif a<=right and right<b:
        ans+=(b-right)//l
        if (b-right)%l==0:
            right=b
        else:
            ans+=1
            right=right+((b-right)//l*l)+l
    #print(a,b,ans,right)
print(ans)