import sys; input=sys.stdin.readline
n,k=map(int,input().split())
if ((1+k)*k)//2>n:
    print(-1)
    exit()
n-=((1+k)*k)//2
if n%k!=0:
    print(k)
    exit()
print(k-1)