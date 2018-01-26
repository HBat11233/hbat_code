#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int f[105];
int vid[101][101];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m),n+m)
    {
        memset(vid,0,sizeof(vid));
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                scanf("%d",&vid[i][j]);
        
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;++i)
        {
            for(int j=m;j>0;--j)
            {   
                for(int k=j;k>0;--k)
                f[j]=max(f[j],f[j-k]+vid[i][k]);
            }
        }
        cout<<f[m]<<endl;
    }
    return 0;
}