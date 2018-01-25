#include <cmath>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>

#define INF 1008
#define DATA 99999999

using namespace std;

bool frem[INF]={false};
double w[INF][INF];

struct IP               //农场坐标 
{
    double x;
    double y;
}v[INF];

inline double td(const int &a,const int &b)   //计算距离
{
    double xx=fabs(v[a].x-v[b].x),yy=fabs(v[a].y-v[b].y);
    return sqrt(xx*xx+yy*yy);
}

int main()
{
    int n,m;
    double ans=0;
    for(int i=0;i<INF;++i)
        for(int j=0;j<INF;++j)
            w[i][j]=DATA;
    //初始化距离数组
    int que=0;
    double los[INF];
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>v[i].x>>v[i].y;
    for(int i=1;i<n;++i)
        for(int j=i+1;j<=n;++j)
            w[i][j]=w[j][i]=td(i,j);
    for(int i=0;i<m;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        w[a][b]=w[b][a]=0;
    }
    //输入完成

    for(int i=1;i<=n;++i)
        los[i]=w[1][i];//核心
    frem[1]=true;
    que++;
    while(que!=n)
    {
        int mx=-1;
        double len=DATA;
        //储存最小值
            for(int j=2;j<=n;++j)
            {
                if(frem[j])continue;//如果在一个树就不看了
                if(len>los[j])//路径是否短
                    mx=j,len=los[j];
            }
        if(len>=DATA)break;
        frem[mx]=true;
        que++;
        ans+=len;
        for(int j=2;j<=n;++j)
        {
            if(frem[j])continue;
            if(los[j]>w[mx][j])los[j]=w[mx][j];
        }
    }
    //cout<<setprecision(2)<<fixed<<ans<<endl;
    double poo=ans-0.005;
    printf("%.2f\n",poo);
    return 0;
}
/*
7 3
1 4
2 9
1 5
4 3
7 7
8 2
9 2
1 4
2 3
7 5
*/