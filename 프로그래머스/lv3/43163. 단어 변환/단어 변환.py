def solution(begin, target, words):
    answer = 0
    
    ####################################
    
    #target이 없으면 0 리턴
    if target not in words:
        return 0
    
    #문자열 길이
    K=len(begin)
    
    queue=[]
    queue.append([begin,0])
    while queue!=[]:
        s=queue[0][0]
        level=queue[0][1]
        queue=queue[1:]
        
        if s==target:
            answer=level
            break
            
        for i in words:
            different=0
            for j in range(K):
                if s[j]!=i[j]:
                    different+=1
                if different>=2:
                    break
            if different==1:
                queue.append([i,level+1])
                words.remove(i)
    
    ####################################
    
    return answer