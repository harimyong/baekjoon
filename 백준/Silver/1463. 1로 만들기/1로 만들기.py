
n=int(input())
global dp
dp=1000000000
def dfs(n,depth):
    global dp
    if n==1 and dp>depth:
        dp=depth
        return
    if depth>dp:
        return
    if n%3==0:
        dfs(n//3,depth+1)
    if n%2==0:
        dfs(n//2,depth+1)
    dfs(n-1,depth+1)
dfs(n,0)
print(dp)