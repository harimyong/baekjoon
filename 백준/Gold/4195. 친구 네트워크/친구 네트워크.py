import sys; 
sys.setrecursionlimit(10**6)
input=sys.stdin.readline
def find(x):
    if parent[x]!=x:
        parent[x]=find(parent[x])
    return parent[x]
def merge(a,b):
    a,b=find(a),find(b)
    if a<=b: parent[b]=a; d[a]+=d[b]
    else: parent[a]=b; d[b]+=d[a]
for _ in range(int(input())):
    d=dict()
    parent=dict()
    for _ in range(int(input())):
        a,b=map(str,input().split())
        if a not in parent:
            parent[a]=a
            d[a]=1
        if b not in parent:
            parent[b]=b
            d[b]=1
        if find(a)!=find(b): merge(a,b)
        print(d[find(a)])