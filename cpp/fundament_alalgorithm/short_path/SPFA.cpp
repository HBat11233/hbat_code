#include <iostream>
#include <cstring>
#include <cmath>

#define MAXN 101
#define MS(x,a) memset(x,a,sizeof(x))
#define DIS(a,b,x,y) sqrt(pow(double(a-x),2)+pow(double(b-y),2))
#define KK() MS(x,0);MS(y,0);MS(a,0);MS(b,0);MS(w,0);MS(frist,-1);MS(nexta,-1);MS(dis,0x7f);dis[1]=0;MS(ko,0);
#define INT() int n,m; int x[MAXN]; int y[MAXN]; double w[MAXN]; int frist[MAXN]; int nexta[MAXN]; int a[MAXN]; int b[MAXN]; double dis[MAXN]; bool ko[MAXN]; int que[MAXN]; int head=0; int tail=1;

using namespace std;



int main()
{
    INT();
    KK();
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>x[i]>>y[i];
    cin>>m;
    for(int i=1;i<=m;++i)
    {
        cin>>a[i]>>b[i];
        w[i]=DIS(x[a[i]],y[a[i]],x[b[i]],y[b[i]]);
        nexta[i]=frist[a[i]];
        frist[a[i]]=i;
    }
    que[head]=1;
    ko[1]=true;
    do
    {
        int k=frist[que[head]];
        while(k!=-1)
        {
            if(dis[b[k]]>dis[a[k]]+w[k])
            {
                dis[b[k]]=dis[a[k]]+w[k];
                if(!ko[b[k]])
                {
                    que[tail]=b[k];
                    tail++;
                }
            }
            k=nexta[k];
        }
        head++;
    }while(head!=tail);
    cout<<dis[5];
    system("pause");
    return 0;
}