import sys
n,k,l=map(int,sys.stdin.readline().split())
answer=[]
possible=0
for _ in range(n):
    a,b,c=map(int,sys.stdin.readline().split())
    if a>=l and b>=l and c>=l:
        if a+b+c>=k:
            possible+=1
            answer.append(a)
            answer.append(b)
            answer.append(c)
print(possible)
print(' '.join(list(map(str,answer))))