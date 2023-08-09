arr=[i for i in range(0,10)]
#s 기호 리스트
#answer 답
result=[]
def bt(s,answer,now):
    if len(answer)==n+1:
        result.append(answer)
        return
    if len(s)==0:
        return
    if s[0]=='>':
        for j in range(0,now):
            if arr[j] not in answer:
                bt(s[1:],answer+[arr[j]],arr[j])
    else:
        for j in range(now+1,10):
            if arr[j] not in answer:
                bt(s[1:],answer+[arr[j]],arr[j])
                    
n=int(input())
s=input().split(' ')
for i in arr:
    bt(s,[i],i)
print(''.join(list(map(str,result[-1]))),''.join(list(map(str,result[0]))),sep='\n')