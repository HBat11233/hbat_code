#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int a[100];
int num[10];

int main()
{
    srand(time(NULL));
    for(int i=0;i<100;++i)
    {
        a[i]=rand()%10;
        num[a[i]]++;
    }
    for(int i=0;i<10;++i)
        cout<<i<<" occurrence number:"<<num[i]<<"\n";
    cout<<"list!\n";
    for(int k=0;k<10;++k)
    {
        for(int i=0;i<10;++i)
        {
            for(int j=0;j<10;++j)
            {
                if(a[i*10+j]==k)cout<<a[i*10+j]<<' ';
                else cout<<"- ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}