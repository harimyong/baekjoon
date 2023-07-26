n,m = map(int, input().split())
 
s = []
 
def dfs(now):
    if len(s)==m:
        print(' '.join(map(str,s)))
        return
    
    for i in range(now, n+1):
        s.append(i)
        dfs(i)
        s.pop()
    
dfs(1)