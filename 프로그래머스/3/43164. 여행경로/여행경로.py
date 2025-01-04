def solution(tickets):     

    graph=dict()
    for fr,to in tickets:
        if fr not in graph:
            graph[fr]=[to]
        else:
            graph[fr].append(to)

    for i in graph:
        graph[i].sort(reverse=True)
    answer=[]
    q=['ICN']
    while q:
        now=q[-1]
        if now not in graph or len(graph[now])==0:
            answer.append(q.pop())
        else:
            q.append(graph[now].pop())
    return answer[::-1]