import sys; input=sys.stdin.readline
n=list(input().rstrip())
ans=-1
n.sort(reverse=True)
if int(''.join(n))%30==0:
    print(''.join(n))
else:
    print(-1)