#include <iostream>

using namespace std;

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    for(int i=n/a;i>=0;--i)
    {
        if((n-i*a)%b==0)
        {
            cout<<"YES\n";
            cout<<i<<' '<<(n-i*a)/b;
            system("pause");
            return 0;
        }
    }
    cout<<"NO\n";
    system("pause");
    return 0;
}