import sys; input=sys.stdin.readline
n=int(input())
now=list(map(int,input().split()))
want=list(map(int,input().split()))
check=[0]*n
ans=0
chk=0
for i in range(n):
    if now[i]==want[i]:
        check[i]=1
        chk+=1
while chk!=n:
    for i in range(n):
        if check[i]==0:
            flag=True if now[i]<want[i] else False
            mincnt=abs(now[i]-want[i])
            left,right=i,i
            for j in range(i+1,n):
                if check[j]==1 or (flag==True and want[j]<now[j]) or (flag==False and now[j]<want[j]):
                    break
                right=j
                mincnt=min(mincnt,abs(now[j]-want[j]))
            
            for j in range(left,right+1):
                if flag:
                    now[j]+=mincnt
                else:
                    now[j]-=mincnt
                if now[j]==want[j]:
                    check[j]=1
                    chk+=1
            
            ans+=mincnt
            break
    #print(*now,mincnt)
print(ans)