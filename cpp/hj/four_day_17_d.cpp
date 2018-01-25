#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#define NUM 800
#define INF 0x3f3f3f3f

using namespace std;


struct IP
{
    int x;
    int y;
    IP(const int a=0,const int b=0)
        :x(a),y(b){}
}v[NUM];

double w[NUM][NUM];
bool frem[NUM];
double los[NUM];
int lastp[NUM];

double td(int i,int j)
{
    double xx=fabs(v[i].x-v[j].x);
    double yy=fabs(v[i].y-v[j].y);
    return sqrt(xx*xx+yy*yy);
}

int main()
{
    int n;
    vector <IP> ans;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d%d",&v[i].x,&v[i].y);
    for(int i=1;i<n;++i)
        for(int j=i+1;j<=n;++j)
            w[i][j]=w[j][i]=td(i,j);
    int m;
    cin>>m;
    for(int i=0;i<m;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        w[a][b]=w[b][a]=0;
    }
    for(int i=2;i<=n;++i)
        los[i]=w[1][i],lastp[i]=1;
    frem[1]=true;
    int num=1;
    while(num!=n)
    {
        int mx=-1;
        double len=INF;
        for(int i=2;i<=n;++i)
        {
            if(frem[i])continue;
            if(len>los[i])
            {
                mx=i;
                len=los[i];
            }
        }
        if(len>=INF)break;
        frem[mx]=true;
        num++;
        if(len!=0)ans.push_back(IP(lastp[mx],mx));
        for(int i=2;i<=n;++i)
        {
            if(frem[i])continue;
            if(los[i]>w[mx][i])los[i]=w[mx][i],lastp[i]=mx;
        }
    }
    for(int i=0;i<ans.size();++i)
        cout<<ans[i].x<<' '<<ans[i].y<<endl;
    return 0;
}