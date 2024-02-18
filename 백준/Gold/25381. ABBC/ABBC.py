import sys; input=sys.stdin.readline
from collections import deque
s=input().rstrip()
ans=0
check=[0]*len(s)
A,B,C=deque(),deque(),deque()
for i in range(len(s)):
    if s[i]=='A':
        A.append(i)
    elif s[i]=='B':
        B.append(i)
    else:
        C.append(i)

while B:
    if C:
        if B[0]<C[0]:
            B.popleft()
            ans+=1
        C.popleft()
    else:
        break

while B:
    if A:
        if A[0]<B[0]:
            A.popleft()
            ans+=1
        B.popleft()
    else:
        break
print(ans)