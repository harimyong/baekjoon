import sys; input=sys.stdin.readline
n=int(input())
s,ans,ans2='','',''
for _ in range(n): s+=input().rstrip()
left,right=0,n-1
while left<=right:
    if s[left]<s[right]:
        ans+=s[left]
        left+=1
    elif s[left]>s[right]:
        ans+=s[right]
        right-=1
    else:
        if left==right:
            ans+=s[left]
            left+=1
        else:
            aleft,aright,flag=left+1,right-1,True
            while aleft<=aright:
                if s[aleft]<s[aright]:
                    break
                elif s[aleft]>s[aright]:
                    flag=False
                    break
                aleft+=1
                aright-=1

            if flag:
                ans+=s[left]
                left+=1
            else:
                ans+=s[right]
                right-=1

for i in range(n):
    print(ans[i],end='')
    if (i+1)%80==0:
        print()