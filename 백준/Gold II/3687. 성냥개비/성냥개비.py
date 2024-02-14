import sys; input=sys.stdin.readline
t=int(input())
dp=[0,0,1,7,4,2,6,8,10,18,22]
for _ in range(t):
    n=int(input())
    max_s=''
    a=n
    while a>3:
        max_s+='1'
        a-=2
    if a==3:
        max_s='7'+max_s
    elif a==2:
        max_s='1'+max_s
    a=n
    min_s=''
    if a<11:
        min_s=str(dp[a])
    else:
        while a>0:
            a-=7
            if a>=0:
                min_s+='8'
            else:
                a+=7
                break
        if a in [2,5,6]:
            min_s=str(dp[a])+min_s
        else:
            if a==1:
                min_s='10'+min_s[1:]
            elif a==3:
                min_s='200'+min_s[2:]
            elif a==4:
                min_s='20'+min_s[1:]
    print(min_s,max_s)
        