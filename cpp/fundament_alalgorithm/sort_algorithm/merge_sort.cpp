#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define MAXNUM 100000

using namespace std;

int num[MAXNUM];
int numy[MAXNUM];

void manum()
{
    srand(time(NULL));
    for(int i=0;i<MAXNUM;++i)
        num[i]=rand()*rand()%MAXNUM;
    return;
}

int msort(int l,int r)
{
    int i,j,k=l;
    if(l==r)return 0;
    int beign=(l+r)/2;
    msort(l,beign);
    msort(beign+1,r);
    for(i=l,j=beign+1;i<=beign&&j<=r;k++)
    {
        if(num[i]<num[j])
        {
            numy[k]=num[i];
            i++;
        }else
        {
            numy[k]=num[j];
            j++;
        }
    }
    if(j<=r)i=j;
    while(k<=r)
    {
        numy[k]=num[i];
        k++;
        i++;
    }
    for(i=l;i<=r;++i)
        num[i]=numy[i];
    return 0;
}

int print()
{
    for(int i=0;i<MAXNUM;++i)
    {
        printf("%d ",num[i]);
        if((i+1)%10==0)cout<<endl;
    }
    return  0;
}

int main()
{
    freopen("m.txt","w",stdout);
    int time1=clock();
    manum();
    msort(0,MAXNUM-1);
    print();
    int time2=clock();
    cout<<time2-time1;
    fclose(stdout);
    return 0;
}