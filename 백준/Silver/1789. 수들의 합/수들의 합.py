import sys; input=sys.stdin.readline
n=int(input())
cnt=0
a=0
while True:
    a+=1
    if (1+a)*a//2<=n:
      cnt+=1
    else:
      break
print(cnt)