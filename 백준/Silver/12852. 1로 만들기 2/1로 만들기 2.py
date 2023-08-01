n=int(input())
global dp
global route
dp=1000000000
route=[n]
def dfs(n,depth,arr):
    global dp
    global route
    if n==1 and dp>depth:
        dp=depth
        route=arr
        return
    if depth>dp:
        return
    if n%3==0:
        dfs(n//3,depth+1,arr+[n//3])
    if n%2==0:
        dfs(n//2,depth+1,arr+[n//2])
    dfs(n-1,depth+1,arr+[n-1])
dfs(n,0,route)
print(dp)
for i in route:
    print(i,end=' ')