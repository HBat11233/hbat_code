#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n,m;
    bool pk[105];
    while(cin>>n>>m)
    {
        memset(pk,0,sizeof(pk));
        int a,b;
        for(int i=0;i<n;++i)
        {
            cin>>a>>b;
            for(int j=a;j<=b;++j)
                pk[j]=true;
        }
        int ans=0;
        for(int i=1;i<=m;++i)
            if(!pk[i])ans++;
        cout<<ans<<'\n';
        for(int i=1;i<=m;++i)
            if(!pk[i])cout<<i<<' ';
        cout<<'\n';
    }
}