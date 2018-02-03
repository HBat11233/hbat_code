#include <iostream>
#include <cstdio>

using namespace std;

const long long MD=1e9+7;

long long pows(long long  n)
{
    long long ans=1;
    long long pos=4;
    while(n)
    {
        if(n&1)
        {
            ans%=MD;
            pos%=MD;
            ans*=pos;
            ans%=MD;
        }
        pos%=MD;
        pos*=pos;
        pos%=MD;
        n=n>>1;
    }
    return ans%MD;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;++i)
    {
        long long  n=1e18;
        cout<<n;
        cin>>n;
        long long ans=(pows(n-1)*2)%MD;
        cout<<ans;
        if(i!=t-1)cout<<endl;
    }
    return 0;
}