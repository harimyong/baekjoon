def solution(n, computers):
    answer = 0
    def dfs(index):
        computers[index][index]=0
        if 1 in computers[index]:
            for i in range(n):
                if computers[index][i]==1:
                    computers[index][i]=0
                    computers[i][index]=0
                    computers[i][i]=0
                    dfs(i)
                        
    for i in range(n):
        if 1 in computers[i]:
            answer+=1
            dfs(i)
    
    return answer