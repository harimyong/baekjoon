import sys; input=sys.stdin.readline
n=int(input())
s=list(input().rstrip())
stack=[-1]
ans=0
for i in range(n):
    if s[i]=='(':
        stack.append(i)
    else:
        if stack:
            stack.pop()
            
        if stack:
            ans=max(ans,i-stack[-1])
        else:
            stack.append(i)
print(ans)