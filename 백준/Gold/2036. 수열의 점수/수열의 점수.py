import sys; input=sys.stdin.readline
n=int(input())
plus,minus,one=[],[],[]
for _ in range(n):
    a=int(input())
    if a>0:
        if a==1: one.append(a)
        else: plus.append(a)
    else:
        minus.append(a)
plus.sort(reverse=True)
minus.sort()
ans=0
for i in range(0,len(plus),2): ans+=plus[i]*plus[i+1] if i+1<len(plus) else plus[i]
for i in range(0,len(minus),2): ans+=minus[i]*minus[i+1] if i+1<len(minus) else minus[i]
print(ans+sum(one))