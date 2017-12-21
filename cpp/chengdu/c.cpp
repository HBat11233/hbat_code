#include <iostream>
#include <string>

using namespace std;

int main()
{
    string n;
    int ans=0;
    cin>>n;
    n="000"+n;
    int i=n.size()-3;
    int a=0;
    for(int j=0;j<3;++j)
    {
        a*=10;
        a+=n[i+j]-'0';
    }
    int p[5][6]=
    {
        {},
        {1},
        {6,2,4,8},
        {1,3,9,7},
        {6,4}
    };
    ans+=1+p[2][a%4]+p[3][a%4]+p[4][a%2];
    ans%=5;
    cout<<ans;
    system("pause");
    return 0;
}