#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int a[100];
bool fa[1000];
int b[100];
bool fb[1000];


int main()
{
    srand(time(NULL));
    for(int i=0;i<100;++i)
    {
        a[i]=100+rand()%900;
        fa[a[i]]=true;
        b[i]=100+rand()%900;
        fb[b[i]]=true;
    }
    for(int i=0;i<10;++i)
    {
        for(int j=0;j<10;++j)
            printf("%d ",a[i*10+j]);
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<10;++i)
    {
        for(int j=0;j<10;++j)
            printf("%d ",b[i*10+j]);
        cout<<endl;
    }
    for(int i=100;i<1000;++i)
    {
        if(!fa[i])
        {
            if(!fb[i])
                cout<<"Both A anb B have no:"<<i<<endl;
            else cout<<"A have no:"<<i<<endl;
        }
        else if(!fb[i]) cout<<"B have no:"<<i<<endl;
    }
    system("pause");
    return 0;
}