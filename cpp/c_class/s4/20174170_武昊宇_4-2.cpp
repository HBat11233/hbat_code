#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int a[100];

int main()
{
    srand(time(NULL));
    for(int i=0;i<100;++i)
        a[i]=rand()%100;
    for(int i=0;i<10;++i)
    {
        for(int j=0;j<10;++j)
            printf("%2d:%2d ",i*10+j,a[i*10+j]);
        cout<<endl;
    }
    int num;
    for(cout<<"search number:";cin>>num;cout<<"search number:")
    {
        bool ko=true;
        for(int i=0;i<100;++i)
        {
            if(a[i]==num)
            {
                if(ko)
                {
                    cout<<"pos:";
                    ko=false;
                }
                cout<<i<<' ';
            }
        }
        if(ko)cout<<"None!";
        cout<<endl;
    }
    return 0;
}