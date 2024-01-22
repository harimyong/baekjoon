import sys
input=sys.stdin.readline
MAX=500000
n=int(input())
seg=[0]*((MAX+1)*4) 
def sum(x):
    ans=0
    while x>0:
        ans+=seg[x]
        x-=(x&-x)
    return ans

def update(x):
    while x<=MAX:
        seg[x]+=1
        x+=(x&-x)

v=[[] for _ in range(MAX+1)]
for _ in range(n):
    a,b=map(int,input().split())
    v[b+210000].append(a+210000)

ans=0
MOD=1000000007
for i in range(MAX,0,-1):
    if v[i]:
        for j in v[i]:
            ans+=(sum(MAX)-sum(j))*sum(j-1)
            ans%=MOD
        for j in v[i]:
            update(j)
print(ans%MOD)