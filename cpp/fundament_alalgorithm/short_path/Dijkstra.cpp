#include <iostream>
#include <cmath>
#include <cstring>
#define DIS(a,b,x,y) sqrt(pow(double(a-x),2)+pow(double(b-y),2))

#define MAXN 100

using namespace std;

int x[MAXN]; 
int y[MAXN];
double w[MAXN][MAXN];
double dis[MAXN];
int n,m;

int main()
{
    memset(w,0x7f,sizeof(w));
    memset(dis,0x7f,sizeof(dis));
    dis[1]=0;
    for(int i=0;i<MAXN;++i)
        w[i][i]=0;
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
        w[x1][y1]=DIS(x[x1],y[x1],x[y1],y[y1]);
        w[y1][x1]=w[x1][y1];
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;++j)
            dis[j]=dis[j]<dis[i]+w[i][j]? dis[j]:dis[i]+w[i][j];
    cout<<dis[5];
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