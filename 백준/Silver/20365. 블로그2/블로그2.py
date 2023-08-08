n=int(input())
s=input()
b,r=0,0
if s[0]=='B':
    b+=1
else:
    r+=1
    
for i in range(1,len(s)):
    if s[i]!=s[i-1]:
        if s[i]=='B':
            b+=1
        else:
            r+=1

if b>r:
    print(r+1)
else:
    print(b+1)