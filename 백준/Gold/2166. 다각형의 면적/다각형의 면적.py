n=int(input())
arr=[list(map(int,input().split())) for _ in range(n)]
FP=arr[0]
a,b=arr[1],arr[2]
def getarea(a,b):
    return (((FP[0]*a[1])+(a[0]*b[1])+(b[0]*FP[1]))-((a[0]*FP[1])+(b[0]*a[1])+(FP[0]*b[1])))/2
area=getarea(a,b)
for i in range(3,n):
    a,b=b,arr[i]
    area+=getarea(a,b)
print("%.1lf" % abs(round(area,1)))
