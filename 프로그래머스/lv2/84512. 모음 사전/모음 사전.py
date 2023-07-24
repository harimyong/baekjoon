def solution(word):
    answer = 0
    alpha=['','A','E','I','O','U']
    li = []
    for i in alpha:
        for j in alpha:
            for k in alpha:
                for n in alpha:
                    for m in alpha:
                        li.append(i+j+k+n+m)
    li.sort()
    
    #공백 없애고
    for i in li:
        if i=='':
            li.remove(i)
    
    
    #중복 없애고
    li=list(set(li))
    li.sort()
    
    for i in range(len(li)):
        if li[i]==word:
            answer=i+1
            
    return answer