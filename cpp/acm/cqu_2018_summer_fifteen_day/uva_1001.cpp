//floyed
#include <bits/stdc++.h>

using namespace std;

struct ips
{
    int x;
    int y;
    int z;
    double r;
    ips(int x=0,int y=0,int z=0,double r=0)
    :x(x),y(y),z(y),r(r){}
}da[105];

double w[105][105];

inline double dt(const ips &a,const ips &b)
{
    double ans=0;
    ans=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
    ans=sqrt(ans);
    ans-=(a.r+b.r);
    if(ans<0)ans=0;
    return ans;
}
int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int o=0;
    int n;
    while(scanf("%d",&n),~n)
    {
        int len=n+2;
        memset(da,0,sizeof(da));
        for(int i=1;i<=n;++i)
            scanf("%d%d%d%lf",&da[i].x,&da[i].y,&da[i].z,&da[i].r);
        scanf("%d%d%d",&da[0].x,&da[0].y,&da[0].z);
        scanf("%d%d%d",&da[n+1].x,&da[n+1].y,&da[n+1].z);
        memset(w,0x7f,sizeof(w));
        for(int i=0;i<len;++i)
            for(int j=0;j<len;++j)
                w[i][j]=dt(da[i],da[j]);
        for(int k=0;k<len;++k)
            for(int i=0;i<len;++i)
                for(int j=0;j<len;++j)
                    w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
        printf("Cheese %d: Travel time = %.0f sec\n",++o,(w[0][n+1]*10));
    }
    return 0;
}