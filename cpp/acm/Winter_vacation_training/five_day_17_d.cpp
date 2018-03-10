//超时代码
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int f[55][100005];
int ans[100005];
int boxw[55];
int len[55];
vector< vector <int> >datas[2];

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        memset(boxw,0,sizeof(boxw));
        memset(len,0,sizeof(len));
        memset(f,0,sizeof(f));
        memset(ans,0,sizeof(ans));
        datas[0].clear();
        datas[0].resize(n+2);
        datas[1].clear();
        datas[1].resize(n+2);
        for(int i=1;i<=n;++i)
        {
            scanf("%d%d",boxw+i,len+i);
            datas[0][i].resize(len[i]);
            datas[1][i].resize(len[i]);
            for(int j=0;j<len[i];++j)
                scanf("%d%d",&datas[0][i][j],&datas[1][i][j]);
        }
        for(int k=1;k<=n;++k)
            for(int i=0;i<len[k];++i)
                for(int j=m;j>=boxw[k]+datas[0][k][i];--j)
                    f[k][j]=max(f[k][j],f[k][j-datas[0][k][i]]+datas[1][k][i]);
        for(int k=1;k<=n;++k)
            for(int j=m;j>boxw[k];--j)
                for(int i=j;f[k][i]&&i>boxw[k];--i)
                    ans[j]=max(ans[j],ans[j-i]+f[k][i]);
        cout<<ans[m]<<endl;
    }
    return 0;
}

//转化01，加if