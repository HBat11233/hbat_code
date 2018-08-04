#include <bits/stdc++.h>

#define INF 100005

using namespace std;

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    long long a,b;
    cin>>a>>b;
    if(a>0)
    {
        if(b>0)
            cout<<0<<' '<<a+b<<' '<<a+b<<' '<<0<<'\n';
        else
            cout<<0<<' '<<b-a<<' '<<a-b<<' '<<0<<'\n';
    }
    else
    {
        if(b>0)
            cout<<a-b<<' '<<0<<' '<<0<<' '<<b-a<<'\n';
        else
            cout<<a+b<<' '<<0<<' '<<0<<' '<<a+b<<'\n';
    }
    return 0;
}