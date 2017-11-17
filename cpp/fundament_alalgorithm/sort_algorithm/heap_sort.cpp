#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define MAXNUM 100000

using namespace std;

int num[MAXNUM+1];

void manum()
{
    srand(time(NULL));
    for(int i=1;i<=MAXNUM;++i)
        num[i]=rand()*rand()%MAXNUM;
    return;
}

int rh(int ro,int length)
{
    int lc=ro*2,rc=ro*2+1;
    if(lc>length)return 0;
    if(rc<=length)
    {
        if(num[ro]>num[lc]||num[ro]>num[rc])
        {
            if(num[lc]<num[rc])
            {
                swap(num[ro],num[lc]);
                rh(lc,length);
            }
            else
            {
                swap(num[ro],num[rc]);
                rh(rc,length);
            }
        }
    }
    else if(num[ro]>num[lc])
        swap(num[ro],num[lc]);
    return 0;
}

int hsort()
{
    for(int i=MAXNUM/2;i>0;--i)
        rh(i,MAXNUM);
    int tail=MAXNUM;
    int i=1;
    while(tail>0)
    {
        cout<<num[1]<<' ';
        if(!(i%10))cout<<endl;
        i++;
        num[1]=num[tail];
        tail--;
        rh(1,tail);
    }
    return 0;
}

int main()
{
    freopen("h.txt","w",stdout);
    int time1=clock();
    manum();
    hsort();
    int time2=clock();
    cout<<time2-time1;
    fclose(stdout);
    return 0;
}