#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <cmath>

using namespace std;

#define LE 100000

int num[LE];

void makenum()
{
    srand(time(NULL));
    for(int i=0;i<LE;++i)
        num[i]=rand()*rand()%LE;
    return;
}

int qsort(int l,int r)
{
    int b=num[(l+r)/2];//�Ƚ�ֵ���� 
    int i=l;
    int j=r;
    while(i<=j)
    {
        while(num[i]<b)i++;
        while(num[j]>b)j--;
        if(i<=j)
        {
        	if(i!=j)//��ַ�ظ���Ϊ0 
        	{
            	num[i]^=num[j];
            	num[j]^=num[i];
            	num[i]^=num[j];
            }
            i++;
            j--;
        }
    }
    if(i<r)qsort(i,r);
    if(l<j)qsort(l,j);
    return 0;
}

int print()
{
    for(int i=0;i<LE;++i)
    {
        cout<<num[i]<<' ';
        if((i+1)%10==0)cout<<endl;
    }
    return 0;
}

int main()
{
    int timea=clock();
    freopen("q.txt","w",stdout);
    makenum();
    qsort(0,LE-1);
    print();
    int timeb=clock();
    cout<<"---"<<timeb-timea;
    fclose(stdout);
}
