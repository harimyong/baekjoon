import sys; input=sys.stdin.readline

n=int(input())
arr=[]
for _ in range(n):
    arr.append(int(input()))

ans=0
stack=[]
for i in range(n):
    while stack!=[] and stack[-1]<=arr[i]:
        stack.pop()
    ans+=len(stack)
    stack.append(arr[i])
print(ans)
