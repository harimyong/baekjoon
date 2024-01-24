s=input().split('-')
ans=0
tmp=[]
for i in s:
    tmp2 = i.split('+')
    ret=0    
    for j in tmp2:
        ret+=int(j)
    tmp.append(ret)
ans=int(tmp[0])
for i in range(1,len(tmp)):
    ans-=tmp[i]
print(ans)