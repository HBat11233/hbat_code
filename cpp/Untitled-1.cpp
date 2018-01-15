#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

typedef struct student
	{
		char no[13];
		char name[20];
		int age;
	}STU;

int main()
	{
		int inputin(struct student x[]);
		int count(STU *p);
		int people_num;
		STU stu[N];
		inputin(stu);
		people_num=count(stu);
		printf("输入的个人信息中，年龄在20岁以上的有%d人",people_num);
		return 0; 
	}
	
int count(STU *p)
	{
		int conter=0,i;
		for(i=0;i<N;i++)
			{
				if(p[i].age>20)
					{
						conter++;
					}
			}
		return conter;
	}
	
int inputin(struct student x[])
	{
		int i,ages=0;
		for(i=0;i<N;i++)
			{
				printf("请输入该学生的姓名:"); 
				gets(x[i].name);
				printf("请输入该学生的年龄:");
				scanf("%d",&ages);
				x[i].age=ages;
			}
            return 0;
	}
	
