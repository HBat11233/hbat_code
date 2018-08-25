#include <bits/stdc++.h>

#define INF 100005

using namespace std;

typedef long long ll;
int dn[INF*2];
int ans[INF*2];

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    ll A;
    while(cin>>n>>A)
    {
        ll sum=0;
        memset(dn,0,sizeof(dn));
        memset(ans,0,sizeof(ans));
        for(int i=0;i<n;++i)
        {
            cin>>dn[i];
            sum+=dn[i];
        }
        ll dt=sum-A;
        for(int i=0;i<n;++i)
        {
            if(dt>=dn[i])ans[i]=0;
            else ans[i]=dn[i]-dt-1;
        }
        dt=A-n;
        for(int i=0;i<n;++i)
        {
            ll te=dn[i]-1-dt;
            if(te>0) ans[i]+=te;
        }
        for(int i=0;i<n;++i)
            cout<<ans[i]<<' ';
        cout<<endl;
    }
    return 0;
}

