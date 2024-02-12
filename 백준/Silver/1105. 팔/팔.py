import sys; input=sys.stdin.readline
l,r=map(int,input().split())
r=str(r)
l=str(l)
if len(l)!=len(r):
    print(0)
    exit()
ans=0
for i in range(len(l)):
    if l[i]!=r[i]:
        break
    else:
        if l[i]==r[i] and l[i]=='8':
            ans+=1
print(ans)