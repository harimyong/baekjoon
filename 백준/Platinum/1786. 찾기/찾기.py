   	
def FailureFunction(pattern):
    F=[0 for _ in range(len(pattern))] 
    j=0
    for i in range(1,len(pattern)):
        while j>0 and pattern[i]!=pattern[j]:
            j=F[j-1]
        if pattern[i]==pattern[j]:
            j+=1
            F[i]=j
    return F

def kmp(word,pattern):
    result=[]
    cnt=0
    tb=FailureFunction(pattern)
    j=0
    for i in range(0,len(word)):
        while j>0 and word[i]!=pattern[j]:
            j=tb[j-1]
        if word[i]==pattern[j]:
            if j==len(pattern)-1:
                cnt+=1
                result.append(i-len(pattern)+2)
                j=tb[j]
            else:
                j+=1
    return result,cnt

w=input()
p=input()
result,cnt=kmp(w,p)
print(cnt)
for i in result:
    print(i,end=' ')
