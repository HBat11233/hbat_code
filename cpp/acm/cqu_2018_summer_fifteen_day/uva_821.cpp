#include<bits/stdc++.h>

using namespace std;

int w[105][105];
bool pk[105];
vector<int>npo;

int main()
{
    int o=0;
    int a,b;
    while(scanf("%d%d",&a,&b),a+b)
    {
        memset(w,0x3f,sizeof(w));
        memset(pk,0,sizeof(pk));
        npo.clear();
        for(int i=0;i<105;++i)
            w[i][i]=0;
        w[a][b]=1;
        while(scanf("%d%d",&a,&b),a+b)
        {
            w[a][b]=1;
            if(!pk[a])
            {
                npo.push_back(a);
                pk[a]=true;
            }
            if(!pk[b])
            {
                npo.push_back(b);
                pk[b]=true;
            }
        }
        int len=npo.size();
        for(int k=0;k<len;++k)
            for(int i=0;i<len;++i)
                for(int j=0;j<len;++j)
                    w[npo[i]][npo[j]]=min(w[npo[i]][npo[j]],w[npo[i]][npo[k]]+w[npo[k]][npo[j]]);
        double ans=0;;
        for(int i=0;i<len;++i)
            for(int j=0;j<len;++j)
                ans+=w[npo[i]][npo[j]];
        ans/=len*(len-1);
        printf("Case %d: average length between pages = %.3lf clicks\n",++o,ans);
    }
    return 0;
}