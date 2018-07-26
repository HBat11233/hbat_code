#include <bits/stdc++.h>

#define INF 505

int d[INF];
int msp[INF][INF];
int ta[INF];
int tb[INF];

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(msp,0,sizeof(msp));
        memset(d,0,sizeof(d));
        memset(ta,0,sizeof(ta));
        memset(tb,0,sizeof(tb));
        for(int i=1;i<=n;++i)
            msp[i][i]=1;
        for(int i=0;i<m;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            d[a]++;
            d[b]++;
            msp[a][b]=msp[b][a]=1;
        }
        for(int i=1;i<=n;++i)
        {
            if(d[i]==n-1)
                for(int x=1;x<=n;++x)
                    msp[x][i]=msp[i][x]=0;
        }

        int p;
        for(p=1;d[p]==n-1&&p<=n;++p);
        for(int i=1,j=0,m=0;i<=n&&p<=n&&(!j||!m);++i)
            if(d[i]==n-1)continue;
            else if(msp[p][i])
            {
                if(j)continue;
                j++;
                for(int l=1;l<=n;++l)
                    ta[l]=msp[i][l];
            }else
            {
                if(m)continue;
                m++;
                for(int l=1;l<=n;++l)
                    tb[l]=msp[i][l];
            }

        for(int i=1;i<=n&&p<=n;++i)
        {
            if(ta[i])
            for(int j=1;j<=n;++j)
                msp[i][j]-=ta[j];
            if(tb[i])
            for(int j=1;j<=n;++j)
                msp[i][j]-=tb[j];
        }

        bool ans=false;
        for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(msp[i][j])ans=true;
        if(ans)printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}