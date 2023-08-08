t=int(input())
from collections import deque
for _ in range(t):
    n=int(input())
    arr=input().split(' ')
    dq=deque()
    dq.append(arr[0])
    standard=arr[0]
    for i in range(1,len(arr)):
        if standard<arr[i]:
            dq.append(arr[i])
        else:
            dq.appendleft(arr[i])
            standard=arr[i]
    print(''.join(dq))