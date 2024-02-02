import sys; input=sys.stdin.readline
n=int(input())
butter=[]
for _ in range(n):
    butter.append(list(map(int,input().split())))
butter.sort()
flag=True
ans=1e12
for i in range(1,n):
    a=butter[i-1]
    b=butter[i]
    
    if a[0]+((a[1]-1)//2) < b[0]-((b[1]-1)//2):
        continue
    else:
        mnt=min((a[1]-1)//2,(b[1]-1)//2)
        dist=b[0]-a[0]
        if 2*mnt<dist:
            dist-=2*mnt
            ans=min(ans,mnt+dist-1)
        else:
            ans=min(ans,(dist-1)//2)
if ans==1e12:
    print('forever')
else:
    print(ans)