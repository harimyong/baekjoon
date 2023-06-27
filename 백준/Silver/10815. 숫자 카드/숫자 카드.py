import sys

a = int(sys.stdin.readline())
ary = list(map(int, sys.stdin.readline().split()))
b = int(sys.stdin.readline())
bry = list(map(int, sys.stdin.readline().split()))
_dict = {}  # 속도는 dictionary!
for i in range(len(ary)):
  _dict[ary[i]] = 0  # 아무 숫자로 mapping
# print(_dict)
for i in range(b):
  if bry[i] in _dict:
    print(1, end=' ')
  else:
    print(0, end=' ')
