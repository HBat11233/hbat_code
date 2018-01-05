#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct stu_type
{ 
 char no[13];
 char name[20];
 int age;
};

int main()
{
    stu_type stu[5];
    for(int i=0;i<5;++i)
    {
        printf("student name:");
        scanf("%s",stu[i].name);
        printf("student age:");
        scanf("%d",&stu[i].age);
    }
    int ans=0;
    for(int i=0;i<5;++i)
    {
        if(stu[i].age>20)ans++;
    }
    printf("20old :%d",ans);
    system("pause");
    return 0;
}