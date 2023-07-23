def solution(genres, plays):
    answer = []
    
    #장르, 번호 지정
    for i in range(len(plays)):
        tmp=plays[i]
        plays[i]=[genres[i],plays[i],i]
    
    #장르 재생 횟수
    dic={}
    for i in plays:
        if i[0] in dic:
            dic[i[0]]+=i[1]
        else:
            dic[i[0]]=i[1]
    dic=sorted(dic.items(), key = lambda x: x[1], reverse=True)
    
    #장르별로 나눔
    result=[]
    for key,value in dic:
        result.append([])
        for i in plays:
            if key==i[0]:
                result[len(result)-1].append(i[1:])
    
    #정렬 및 장르별 2개씩 뽑음
    for i in range(len(result)):
        result[i].sort(key=lambda x: (-x[0],x[1]))
        result[i]=result[i][0:2]
    
    #번호 뽑음
    for i in result:
        for j in i:
            answer.append(j[1])
    
    
    return answer