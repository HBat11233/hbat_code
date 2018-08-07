#include <cstring>
#include <iostream>
#include <cstdio>
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;


int main()
{
    int n;
    while(cin>>n)
    {
        int ans=0;
        int los[n+1];
        int w[n+1][n+1];
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                cin>>w[i][j];
        for(int i=0;i<=n;++i)
            w[i][i]=INF;
        bool pk[n+1];
        mem(pk,0);
        for(int i=1;i<=n;++i)
            los[i]=w[1][i];
        pk[1]=true;
        int num=1;
        while(num!=n)
        {
            int mx=-1;
            int len=INF;
            for(int i=2;i<=n;++i)
                if(los[i]<len&&!pk[i])
                {
                    len=los[i];
                    mx=i;
                }
            if(len>=INF)break;
            ans+=len;
            pk[mx]=true;
            num++;
            for(int i=2;i<=n;++i)
                if(!pk[i])los[i]=min(los[i],w[mx][i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}