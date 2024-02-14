import sys; input=sys.stdin.readline
n=int(input())
arr=list(map(int,input().split()))
tot=sum(arr)
if tot%3!=0:
    print('NO')
    exit()
cnt=0
for i in range(n):
    cnt+=arr[i]//2
if cnt>=tot//3:
    print('YES')
else:
    print('NO')