#include <iostream>
#include <cstring>
#include <cmath>

#define DIS(a,b,x,y) sqrt(pow(double(a-x),2)+pow(double(b-y),2))
#define MS(x,b) memset(x,b,sizeof(x))
#define MAXN 100

using namespace std;

int n,m;
int x[MAXN];
int y[MAXN];
double w[MAXN];
int bw[MAXN];
int ew[MAXN];
double dis[MAXN];

int main()
{
    MS(x,0);
    MS(y,0);
    MS(bw,-1);
    MS(ew,-1);
    MS(w,0x7f);
    MS(dis,0x7f);
    dis[1]=0;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>x[i]>>y[i];
    cin>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>bw[i]>>ew[i];
        w[i]=DIS(x[bw[i]],y[bw[i]],x[ew[i]],y[ew[i]]);
    }
    for(int i=0;i<n-1;++i)
    {
        for(int j=1;j<=m;++j)
            dis[ew[j]]=dis[ew[j]]<dis[bw[j]]+w[j]? dis[ew[j]]:dis[bw[j]]+w[j];
    }
    cout<<dis[5];
    system("pause");
    return 0;
}