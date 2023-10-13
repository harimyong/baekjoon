def solution(n, arr1, arr2):
    answer = []
    
    def makebinary(num):
        sen=""
        while num!=0:
            if num%2==0:
                sen="0"+sen
            else:
                sen="1"+sen
            num//=2
        if len(sen)<n:
            sen=("0"*(n-len(sen)))+sen
        return list(sen)
    
    for i in range(n):
        temp1=makebinary(arr1[i])
        temp2=makebinary(arr2[i])
        res=""
        print(temp1,temp2)
        for j in range(n):
            if int(temp1[j]) or int(temp2[j]):
                res+="#"
            else:
                res+=' '
        answer.append(res)
            
    
    return answer

print(solution(6,	[46, 33, 33 ,22, 31, 50]
,[27 ,56, 19, 14, 14, 10]
))