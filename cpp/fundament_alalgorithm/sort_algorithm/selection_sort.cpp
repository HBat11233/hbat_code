#include <iostream>
#include <ctime>
#include <cmath>
#include <algorithm>

#define LE 100000

using namespace std;

int num[LE];

int print()
{
    for(int i=0;i<LE;++i)
    {
        cout<<num[i]<<" ";
        if((i+1)%10==0)cout<<endl;
    }
    return 0;
}

int manum()
{
    srand(time(NULL));
    for(int i=0;i<LE;++i)
        num[i]=rand()*rand()%LE;
    return  0;
}

int s_sort()//脑洞大开
{
    if(num[0]>num[1])swap(num[0],num[1]);
    int p=0;
    for(int i=2;i<LE;++i)
    {
        if(num[p]<num[i])//哨兵后找
        {
            for(;p<i;++p)
            {
                if(num[p]>num[i])
                {
                    int temp=num[i];
                    for(int j=i-1;j>=p;--j)
                    {
                        num[j+1]=num[j];
                    }
                    num[p]=temp;
                    break;
                }
            }
        }
        else
        {
            for(;p>=0;--p)//哨兵前找
            {
                if(num[p]<num[i])
                {
                    int temp=num[i];
                    for(int j=i-1;j>=p+1;--j)
                    {
                        num[j+1]=num[j];
                    }
                    num[p+1]=temp;
                    break;
                }
            }
            if(p==-1)
            {
                p=0;
                int temp=num[i];
                for(int j=i-1;j>=p;--j)
                {
                    num[j+1]=num[j];
                }
                num[p]=temp;
            }
        }
    }
    return 0;
}

int main()
{
    int timea=clock();
    freopen("s.txt","w",stdout);
    manum();
    s_sort();
    print();
    int timeb=clock();
    cout<<"----"<<timeb-timea;
    fclose(stdout);
    return 0;
}