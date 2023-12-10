

while True:
    s=input()
    if s=='#':
        break
    tot=0
    for i in list(s):
        if i in ['a','e','i','o','u','A','E','I','O','U']:
            tot+=1
    print(tot)