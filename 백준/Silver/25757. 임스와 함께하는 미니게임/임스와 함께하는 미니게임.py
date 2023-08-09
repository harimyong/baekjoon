import sys
n,game=input().split()
n=int(n)
humans={}
for _ in range(n):
    name=sys.stdin.readline().rstrip()
    if name not in humans:
        humans[name]=1
if game=='Y':
    n=1
elif game=='F':
    n=2
else:
    n=3
print((len(humans)//(n)))