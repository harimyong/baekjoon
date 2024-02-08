import sys; input=sys.stdin.readline
n=list(input().rstrip())
now='.'
zero,one=0,0
for i in n:
    if now!=i:
        if i=='0':
            zero+=1
            now='0'
        else:
            one+=1
            now='1'
print(min(zero,one))
