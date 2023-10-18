n = int(input())
string = list(input())
sum=0
for i in range(0,n):
  sum+=(ord(string[i])-96)*(31**i)

print(sum%1234567891)