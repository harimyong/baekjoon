n,m = map(int,input().split())
want=input().split()
queue=[]
for i in range(n):
  queue.append(str(i+1))

answer=0

def findIndex(arr,n):
  for i in range(len(arr)):
    if n==arr[i]:
      return i
  return -1


def calculate(mode,arr,n,times):
  if mode==2:
    while arr[0]!=n:
      arr=arr[1:]+arr[:1]
      times+=1
  else:
    while arr[0]!=n:
      arr=arr[len(arr)-1:]+arr[0:len(arr)-1]
      times+=1
  return arr[1:], times
  
for i in want:
  if findIndex(queue,i)==0:
    queue=queue[1:]
  else:
    if len(queue)%2==0:
      if findIndex(queue,i)>=len(queue)//2:
        queue,answer=calculate(3,queue,i,answer)
      else:
        queue,answer=calculate(2,queue,i,answer)
    else:
      if findIndex(queue,i)<=len(queue)//2:
        queue,answer=calculate(2,queue,i,answer)
      else:
        queue,answer=calculate(3,queue,i,answer)
        
print(answer)