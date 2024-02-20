import sys; input=sys.stdin.readline
c,n=map(int,input().split())
check=[0]*c
chicken,cow=[],[]
for i in range(c):
    chicken.append((int(input()),i))
chicken.sort()
for i in range(n):
    a,b=map(int,input().split())
    cow.append((a,b))
cow.sort(key=lambda x:(x[1],x[0]))

ans=0
for a,b in cow:
    for t,idx in chicken:
        if check[idx]==0 and a<=t<=b:
            check[idx]=1
            ans+=1
            break
print(ans)       