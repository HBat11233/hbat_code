class Student:
    def __init__(self,name,classes):
        self.grades = {}
        self.name = name
        for items in classes:
            self.grades[items] = 0

    def add_grade(self,class_name,grade):
        self.grades[class_name] = grade

    def display(self):
        print(self.name,':',self.grades)

stud_num = int(input('Please input the number of student: '))
class_num = int(input('Please input the number of classes: '))

classes = []
for i in range(class_num):
    class_name = input('Class name: ')
    classes.append(class_name)

info_dict = []
for _ in range(stud_num):
    student_name = input('Please input a student\'s name: ')
    student = Student(student_name,classes)
    info_dict.append(student)
    for i in range(class_num):
        grade = int(input('Please input a grade: '))
        student.add_grade(classes[i],grade)

for stud in info_dict:
    stud.display()