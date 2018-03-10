//poj 1258
#include <cstring>
#include <iostream>
#include <cstdio>
#define INF 0x3f3f3f3f

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
        bool frem[n+1];
        memset(frem,0,sizeof(frem));
        for(int i=1;i<=n;++i)
            los[i]=w[1][i];
        int num=1;
        frem[1]=true;
        while(num!=n)
        {
            int mx=-1;
            int len=INF;
            for(int i=2;i<=n;++i)
                if(los[i]<len && !frem[i])
                    mx=i,len=los[i];
            if(len>=INF)break;
            ans+=len;
            frem[mx]=true;
            num++;
            for(int i=2;i<=n;++i)
            {
                if(los[i]>w[mx][i] && !frem[i])
                    los[i]=w[mx][i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}