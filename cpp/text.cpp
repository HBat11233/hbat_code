#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int func(int &n)
{
    int i,j;
    int ans[22][22]={{0}};
    int w[22][22];
    memset(w,0x7fffffff,sizeof(w));
    while(scanf("%d%d",&i,&j),i)
    {
        w[i][j]=0;
        w[j][i]=0;
        ans[i][j]++;
        ans[j][i]++;
    }
    for(int k=1;k<=n;++k)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(i==j)continue;
                ans[i][j]+=ans[i][k]*ans[k][j];
            }
        }
    }
    cout<<ans[1][n];
    return 0;
}

int main()
{
    int n;
    while(~scanf("%d",&n))
        func(n);
    return 0;
}