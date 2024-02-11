import sys; input=sys.stdin.readline
n=int(input())
s=input().rstrip()
s=s.replace('LL','C')
arr=('*'*len(s))+'*'
if len(arr)>=n:
    print(n)
else:
    print(len(arr))