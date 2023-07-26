n,m = map(int, input().split())
ary=list(map(int, input().split()))
ary.sort()

def dfs(li, arr, now):
    if now==m:
        print(' '.join(map(str,arr)))
        return
    
    for i in range(len(li)):
        arr.append(li[i])
        dfs(li[:i]+li[i+1:], arr, now+1)
        arr.pop()

dfs(ary,[],0)
