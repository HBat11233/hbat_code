#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n, k, l, c, d, p, nl, np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    nl*=n;
    np*=n;
    k*=l;
    c*=d;
    ll ans=0x7fffffff;
    ans=min(k/nl,min(c/n,p/np));
    cout<<ans;
    return 0;
}