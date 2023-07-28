n=int(input())

for i in range(n):
    a=int(input())
    answer=0
    def dfs(n):
        global answer
        if n>a:
            return
        if n==a:
            answer+=1
            return
        
        dfs(n+1)
        dfs(n+2)
        dfs(n+3)

    dfs(0)
    print(answer)