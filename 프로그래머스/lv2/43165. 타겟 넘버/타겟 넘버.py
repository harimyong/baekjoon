def solution(numbers, target):
    answer = 0
    def dfs(nums,total,index):
        if index==len(nums):
            if total==target:
            
                return answer+1
            else:
          
                return answer
        else:
            
            return dfs(nums,total+nums[index],index+1)+answer+dfs(nums,total-nums[index],index+1)+answer
    answer=dfs(numbers,0,0)
    return answer