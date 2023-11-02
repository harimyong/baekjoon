import sys
input=sys.stdin.readline

n=int(input())
ans=list(map(int,input().split()))
arr=ans.copy()
ans.sort()
temp=[]
result=[]
now=1
while arr:
    cur=arr[0]
    arr=arr[1:]
    if cur==now:
        result.append(cur)
        now+=1
    else:
        temp.append(cur)
    
    while temp:
        if temp[len(temp)-1]==now:
            result.append(temp[len(temp)-1])
            now+=1
            temp.pop()
        else:
            break

if result==ans:
    print('Nice')
else:
    print('Sad')
