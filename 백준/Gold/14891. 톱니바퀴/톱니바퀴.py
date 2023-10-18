arr=[list(map(int,list(input()))) for _  in range(4)]
ans=0
t=int(input())
for _ in range(t):
    a,b=map(int,input().split())

    #도는 바퀴 설정
    if a<=2:
        if a==1:
            arrow=[b,-b,0,0]
            if arr[0][2]==arr[1][6]:
                arrow[1]=0
            if arrow[1]!=0 and arr[1][2]!=arr[2][6]:
                arrow[2]=b
        elif a==2:
            arrow=[-b,b,-b,0]
            if arr[0][2]==arr[1][6]:
                arrow[0]=0
            if arr[1][2]==arr[2][6]:
                arrow[2]=0
        
        if arrow[2]!=0 and arr[2][2]!=arr[3][6]:
            arrow[3]=-arrow[2]
        
    else:
        if a==3:
            arrow=[0,-b,b,-b]
            if arr[1][2]==arr[2][6]:
                arrow[1]=0
            if arr[2][2]==arr[3][6]:
                arrow[3]=0 
        else:
            arrow=[0,0,-b,b]
            if arr[2][2]==arr[3][6]:
                arrow[2]=0
            if arrow[2]!=0 and arr[1][2]!=arr[2][6]:
                arrow[1]=b

        if arr[1]!=0 and arr[0][2]!=arr[1][6]:
            arrow[0]=-arrow[1]
            
    for i in range(4):
        if arrow[i]==1:
            arr[i]=[arr[i][7]]+arr[i][0:7]
        elif arrow[i]==-1:
            arr[i]=arr[i][1:8]+[arr[i][0]]

ans=0
for i in range(4):
    if arr[i][0]:
        ans+=(2**i)         
print(ans)  
