LED=[[1,1,1,0,1,1,1],
     [0,0,1,0,0,1,0],
     [1,0,1,1,1,0,1],
     [1,0,1,1,0,1,1],
     [0,1,1,1,0,1,0],
     [1,1,0,1,0,1,1],
     [1,1,0,1,1,1,1],
     [1,0,1,0,0,1,0],
     [1,1,1,1,1,1,1],
     [1,1,1,1,0,1,1]]
N,K,P,X=map(int,input().split())
X=(K-len(str(X)))*'0'+str(X)
ans=0
for i in range(1,N+1):
    if int(X)==i: continue
    i=(K-len(str(i)))*'0'+str(i)
    diff=0
    for j in range(K):
        for k in range(7):
            if LED[int(i[j])][k]!=LED[int(X[j])][k]: diff+=1
    if diff<=P: ans+=1
print(ans)