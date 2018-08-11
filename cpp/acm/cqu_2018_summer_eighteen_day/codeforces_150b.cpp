#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

typedef long long ll;
ll n,m,k;

ll c[2005][3];

ll pows(ll a,ll b)
{
    ll ans=1;
    ll te=a%MOD;
    while(b)
    {
        if(b&1)ans=(ans*te)%MOD;
        te=(te*te)%MOD;
        b>>=1;
    }
    return ans;
}

int main()
{
    c[1][1]=1;
    c[2][1]=2;
    c[2][2]=1;
    for(int i=2;i<=2000;++i)
        c[i][1]=i;
    for(int i=2;i<=2000;++i)
        c[i][2]=c[i-1][2]+c[i-1][1];
    cin>>n>>m>>k;
    if(n<k||k==1)cout<<pows(m,n);
    else
    {
        if(k==n)
        {
            if(k%2==0)
                cout<<pows(m,k>>1);
            if(k%2==1)
                cout<<pows(m,(k>>1)+1);
        }
        else if(k%2==0)
            cout<<m;
        else
            cout<<((c[m][2]*2)%MOD+m)%MOD;
    }
    return 0;
}