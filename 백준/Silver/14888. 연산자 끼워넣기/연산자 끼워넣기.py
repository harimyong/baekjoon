n=int(input())
nums=list(map(int,input().split()))
arr=list(map(int,input().split()))
Max=-10000000000    
Min=10000000000
def dfs(nums,result):
    global Max
    global Min
    if nums==[]:
        Max=max(Max,result)
        Min=min(Min,result)
        return
    for i in range(len(arr)):
        if arr[i]==0:
            continue
        arr[i]-=1
        if i==0:
            dfs(nums[1:],result+nums[0])
        elif i==1:
            dfs(nums[1:],result-nums[0])
        elif i==2:
            dfs(nums[1:],result*nums[0])
        elif i==3:
            if result<0:
                dfs(nums[1:],-1*(abs(result)//nums[0]))
            else:
                dfs(nums[1:],result//nums[0])
        arr[i]+=1
dfs(nums[1:],nums[0])
print(Max,Min,sep='\n')