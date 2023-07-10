import sys
a,b=map(int,sys.stdin.readline().split())
li={}
for i in range(a):
    name=sys.stdin.readline().rstrip()
    li[name]=str(i+1)
    li[str(i+1)]=name
for i in range(b):
    s=sys.stdin.readline().rstrip()
    print(li[s])