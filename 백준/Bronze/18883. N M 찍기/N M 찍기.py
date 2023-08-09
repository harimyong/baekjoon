n,m=map(int,input().split())
i=1
for _ in range(n):
    arr=[j for j in range(i,i+m)]
    i+=m
    print(' '.join(list(map(str,arr))))