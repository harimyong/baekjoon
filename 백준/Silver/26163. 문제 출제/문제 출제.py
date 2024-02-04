import sys; input=sys.stdin.readline
arr=list(map(int,input().split()))
ans=0
for a in range(20):
    for b in range(20):
        for c in range(20):
            for d in range(20):
                for e in range(20):
                    if a+b+c+d+e<=3:
                        if a*1+b*2+c*3+d*4+e*5<=10:
                            ans=max(ans,arr[0]*a+arr[1]*b+arr[2]*c+arr[3]*d+arr[4]*e)
                    else:
                        if a*1+b*2+c*3+d*4+e*5<=15:
                            ans=max(ans,arr[0]*a+arr[1]*b+arr[2]*c+arr[3]*d+arr[4]*e)
print(ans)