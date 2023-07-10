a=int(input())
dic={}
for i in range(a):
    name, el=input().split()
    dic[name]=el
dic=sorted(dic.items(), key=lambda x:x[0], reverse=True)
for i in dic:
    if i[1]=='enter':
        print(i[0])