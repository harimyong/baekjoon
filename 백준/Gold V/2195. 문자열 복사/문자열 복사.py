s,p=input(),input()
a,n=1,''
for i in p:
    if n+i in s:
        n+=i
    else:
        a,n=a+1,i
print(a)