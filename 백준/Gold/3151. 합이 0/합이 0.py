from bisect import bisect_left
import sys; input=sys.stdin.readline
N=int(input())
arr=list(map(int,input().split()))
arr.sort()
ans=0
for i in range(N-2):
    s,e=i+1,N-1
    while s<e:
        t=arr[i]+arr[s]+arr[e]
        if t==0:
            if arr[s]==arr[e]: ans+=(e-s)
            else: ans+=(e-bisect_left(arr,arr[e])+1)
            s+=1
        elif t>0: e-=1
        elif t<0: s+=1
print(ans)