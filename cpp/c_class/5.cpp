#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct vnum
{
    int pos;
    int num;
    vnum *next;
    vnum()
        :pos(0),num(0),next(NULL){}
    int size()
    {
        vnum *p=this;
        while(p->next!=NULL)
            p=p->next;
        return p->pos;
    }
};

int main(int argc,char *argv[])
{
    FILE *fp1[3]={fopen("a.dat","r"),fopen("b.dat","r"),fopen("c.dat","w")};
    if(fp1[1]==NULL||fp1[1]==NULL)
    {
        printf("error:Can not find file!\n");
        system("pause");
        return 1;
    }
    vnum *head=NULL,*p=NULL;
    int temp;
    for(int j=0,i=0;j<2;++j)
        for(;~fscanf(fp1[j],"%d",&temp);i++)
        {
            if(p==NULL)
            {
                p=(vnum *)malloc(sizeof(vnum));
                if(head==NULL)head=p;
            }
            else
            {
                p->next=(vnum *)malloc(sizeof(vnum));
                p=p->next;
            }
            p->pos=i;
            p->num=temp;
            p->next=NULL;
        }
    int length=head->size();
    vnum *a=head;
    for(int i=0;i<length-1;++i)
    {
        a=head;
        for(int j=0;j<length-1-i;++j)
        {
            if(a->num>a->next->num)
            {
                a->num^=a->next->num;
                a->next->num^=a->num;
                a->num^=a->next->num;
            }
            a=a->next;
        }
    }
    a=head;
    for(int i=0;a!=NULL;++i)
    {
        fprintf(fp1[2],"%d ",a->num);
        a=a->next;
    }
    system("pause");
    return 0;
}