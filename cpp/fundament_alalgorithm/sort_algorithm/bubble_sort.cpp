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
        num[i]=rand()%LE;
    return  0;
}

int bsort()
{
    for(int i=0;i<LE-1;++i)
    {
        for(int j=1;j<LE;++j)
        {
            if(num[j-1]>num[j])
            {
                num[j-1]^=num[j];
                num[j]^=num[j-1];
                num[j-1]^=num[j];
            }
        }
    }
    return 0;
}

int main()
{
    int timea=clock();
    freopen("b.txt","w",stdout);
    manum();
    bsort();
    print();
    int timeb=clock();
    cout<<"---"<<timeb-timea;
    fclose(stdout);
    return 0;
}