n=int(input())
from math import factorial

arr=list(str(factorial(n)))
cnt=0
for i in arr[::-1]:
    if i=='0':
        cnt+=1
    else:
        break
print(cnt)