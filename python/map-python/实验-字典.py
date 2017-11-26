stud_num = int(input('Please input the number of student: '))
class_num = int(input('Please input the number of classes: '))

classes = []
for i in range(class_num):
    class_name = input('Class name: ')
    classes.append(class_name)

info_dict = {}
for _ in range(stud_num):
    student_name = input('Please input a student\'s name: ')
    info_dict[student_name] = {}
    for i in range(class_num):
        grades = int(input(classes[i]+': '))
        info_dict[student_name][classes[i]] = grades

for i in info_dict.keys():
    print(i,':',info_dict[i])