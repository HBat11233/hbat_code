//prim最小生成树
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int maps[2005][2005];
string str[2005];
int n;

inline int dat(int &a,int &b)
{
    int ans=0;
    if(a==b)return ans;
    for(int i=0;i<str[a].size();++i)
        if(str[a][i]!=str[b][i])ans++;
    return ans;
}

int prim()
{
    int ans=0;
    int dt[2005]={0};
    bool pk[2005]={0};
    pk[1]=true;
    for(int i=1;i<=n;++i)
        dt[i]=maps[1][i];
    int ipos=0;
    int nu=0x7fffffff;
    do
    {
        ipos=0;
        nu=0x7fffffff;
        for(int i=1;i<=n;++i)
        {
            if(pk[i]||dt[i]>=nu)continue;
            nu=dt[i];
            ipos=i;
        }
        if(!ipos)break;
        pk[ipos]=true;
        ans+=nu;
        for(int i=1;i<=n;++i)
            if(!pk[i])dt[i]=maps[ipos][i]<dt[i]?maps[ipos][i]:dt[i];
    }while(ipos!=0);
    return ans;
}

int main()
{
    while(scanf("%d",&n),n)
    {
        for(int i=1;i<=n;++i)
            cin>>str[i];
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                maps[i][j]=maps[j][i]=dat(i,j);
        cout<<"The highest possible quality is 1/"<<prim()<<".\n";
    }
    return 0;
}