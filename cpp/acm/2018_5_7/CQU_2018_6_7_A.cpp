//SCU_4520
#include <bits/stdc++.h>

using namespace std;

#define InF 505
#define mem(a,n) memset(a,n,sizeof(a))

int rt[InF],ct[InF],dt[InF];
bool msp[InF][InF];

int t;
int n,m;
int par[InF];

bool con()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(msp[i][j])
                for(int k=1;k<=n;++k)
                    msp[i][k]=msp[i][k]||msp[j][k];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(!msp[i][j])
                return false;
    return true;
}

int Find (int x) 
{
    return par[x] == -1 ? x : par[x] = Find (par[x]);
}
void Union (int a, int b) {
    int pa = Find (a), pb = Find (b);
    if (pa != pb) par[pb] = pa;
}

bool connected() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (par[i] == -1) cnt ++;
    }
    return cnt <= 1;
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        mem(msp,0);
        mem(rt,0);
        mem(ct,0);
        mem(dt,0);
        mem(par,-1);
        for(int i=1;i<=m;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            rt[a]++;
            ct[b]++;
            msp[a][b]=msp[b][a]=true;
            Union(a,b);
            dt[a]++;
            dt[b]++;
        }
        if(n==1)printf("Yes Yes\n");
        else
        {
            //warshall要跑两遍
            con();
            bool f0=con();
            if(!f0)printf("No No\n");
            else
            {
                int flag=0;
                for(int i=1;i<=n;++i)
                    if(dt[i]&1)flag++;
                if(flag==0||flag==2)printf("Yes ");
                else printf("No ");
                flag=0;
                int s=-1,t=-1;
                for(int i=0;i<=n;++i)
                {
                    if(rt[i]>ct[i])s=i,flag++;
                    else if(rt[i]<ct[i])t=i,flag++;
                }
                if(flag==0||((flag==2)&&~s&&~t&&(rt[s]-ct[s]==1)&&(rt[t]-ct[t]==-1)))printf("Yes\n");
                else printf("No\n");
            }
        }
    }
    return 0;
}