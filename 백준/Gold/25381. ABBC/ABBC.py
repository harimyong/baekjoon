import sys; input=sys.stdin.readline
from collections import deque
s=input().rstrip()
ans=0
check=[0]*len(s)
A,B=deque(),deque()
for i in range(len(s)-1,-1,-1):
    if s[i]=='A':
        A.append(i)
    elif s[i]=='B':
        B.append(i)

for i in range(len(s)-1,-1,-1):
    if check[i]==0 and s[i]=='B':
        while A and A[0]>i:
            A.popleft()
        if A and A[0]<i:
            check[i]=check[A[0]]=1
            ans+=1
            A.popleft()

    if check[i]==0 and s[i]=='C':
        while B and B[0]>i:
            B.popleft()
        if B and B[0]<i:
            check[i]=check[B[0]]=1
            ans+=1
            B.popleft()
print(ans)