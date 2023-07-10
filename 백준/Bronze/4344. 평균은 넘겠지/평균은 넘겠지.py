import sys

N = int(sys.stdin.readline())

for i in range(N):
    students = list(map(int, sys.stdin.readline().split()))
    num_of_students = students.pop(0)
    mean = sum(students)/num_of_students
    
    mean_over_students = sum(list(map(lambda x : x>mean, students)))
    ratio = (mean_over_students / num_of_students) * 100
    print("{:.3f}%".format(ratio))