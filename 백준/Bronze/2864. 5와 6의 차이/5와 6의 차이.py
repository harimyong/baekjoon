import sys; input=sys.stdin.readline
a,b=map(int,input().split())
a,b=str(a),str(b)
mx=int(a.replace('5','6'))+int(b.replace('5','6'))
mn=int(a.replace('6','5'))+int(b.replace('6','5'))
print(mn,mx)