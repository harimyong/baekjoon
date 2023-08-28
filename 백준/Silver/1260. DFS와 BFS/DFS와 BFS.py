#DFS
def dfs(graph, v, visited):
  visited[v]=True
  print(v, end=' ')
  for i in graph[v]:
    if not visited[i]:
      dfs(graph, i, visited)


#BFS
from collections import deque

def bfs(graph2, start, visited2):
  queue = deque([start])
  visited2[start]=True
  while queue:
    v=queue.popleft()
    print(v, end=' ')
    for i in graph2[v]:
      if not visited2[i]:
        queue.append(i)
        visited2[i]=True
        
# 그래프 입력
graph=[[]]
temp=[[]]
a,b,c=map(int,input().split())
for i in range(a):
  graph.append([])
  temp.append([])
  
for i in range(b):
  x,y = map(int,input().split())
  graph[x].append(y)
  graph[y].append(x)
  graph[x].sort()
  graph[y].sort()

for i in range(a+1):
  for v in graph[i]:
      if v not in temp[i]:
          temp[i].append(v)
        
graph=temp
graph2=graph
visited = [False]*(a+1)
visited2= [False]*(a+1)

dfs(graph,c,visited)
print()
bfs(graph2,c,visited2)

