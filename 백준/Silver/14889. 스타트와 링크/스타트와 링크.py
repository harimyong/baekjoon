
import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**5)
n=int(input())
arr=[list(map(int,input().split())) for _ in range(n)]

visit=[0 for _ in range(n)]
ans=2147000000

def back(idx,cnt):
    if cnt==n//2:
        global ans
        tota=0
        totb=0
        for i in range(n):
            for j in range(n):
                if visit[i] and visit[j]:
                    tota+=arr[i][j]
                elif not visit[i] and not visit[j]:
                    totb+=arr[i][j]
        ans=min(ans,abs(tota-totb))
        return

    for i in range(idx,n):
        if not visit[i]:
            visit[i]=1
            back(i+1,cnt+1)
            visit[i]=0

back(0,0)
print(ans)