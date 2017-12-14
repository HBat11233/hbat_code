#include <iostream>
#include <cmath>

using namespace std;

double nj(int n)
{
    if(n==0)return 1.0;
    return n*nj(n-1);
}

int main()
{
    double x;
    double e;
    int i=0;
    cout<<"Input cox(x)  x:";
    cin>>x;
    cout<<"Inout e:";
    cin>>e;
    int n=0;
    double temp;
    double ans=0;
    do
    {
        temp=pow(x,n)/nj(n);
        ans+=i%2==0? temp:-temp;
        n+=2;
        i++;
    }while(temp>e);
    cout<<"cox(x)="<<ans;
    system("pause");
    return 0;
}