def solution(id_list, report, k):
    answer = []
    report_do={}
    for i in report:
        tmp=i.split(' ')
        if tmp[0] not in report_do:
            report_do[tmp[0]]=[tmp[1]]
        else:
            if tmp[1] not in report_do[tmp[0]]:
                report_do[tmp[0]].append(tmp[1])
                
    reported={}
    for i in report_do:
        for j in report_do[i]:
            if j not in reported:
                reported[j]=1
            else:
                reported[j]+=1
                
    for i in id_list:
        tmp=0
        if i in report_do:
            for j in report_do[i]:
                if reported[j]>=k:
                    tmp+=1
        answer.append(tmp)
    
    return answer