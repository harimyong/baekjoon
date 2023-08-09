import sys
n,m=map(int,sys.stdin.readline().split())
p=0
print((((n//2)*m if n>1 else 0) + (0 if n%2==0 else m//2)))