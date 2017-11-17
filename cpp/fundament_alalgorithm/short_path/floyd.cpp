#include <iostream>
#include <cmath>
#include <cstring>
#define DIS(a,b,x,y) sqrt(pow(double(a-x),2)+pow(double(b-y),2))

#define MAXN 100

using namespace std;

int x[MAXN]; 
int y[MAXN];
double dis[MAXN][MAXN];
int n,m;

int main()
{
    memset(dis,0x7f,sizeof(dis));
    for(int i=0;i<MAXN;++i)
        dis[i][i]=0;
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>x[i]>>y[i];
    cin>>m;
    for(int j=1;j<=m;++j)
    {
        int x1,y1;
        cin>>x1>>y1;
        dis[x1][y1]=DIS(x[x1],y[x1],x[y1],y[y1]);
        dis[y1][x1]=dis[x1][y1];
    }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                dis[i][j]=dis[i][j]<=dis[i][k]+dis[k][j]? dis[i][j]:dis[i][k]+dis[k][j];
    cin>>n>>m;
    cout<<dis[n][m];
    system("pause");
    return 0;
}
/*
5
0 2
2 0
2 2
0 2
3 1
5
1 2
1 3
1 4
2 5
3 5
1 5
*/
