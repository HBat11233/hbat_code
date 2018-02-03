#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int f[100010];
int v[100010];
int w[100010];
int s[20][20];

int main()
{
    int nu;
    cin>>nu;
    while(nu--)
    {
        int n,m;
        memset(s,0,sizeof(s));
        memset(f,0,sizeof(f));
        memset(v,0,sizeof(v));
        memset(w,0,sizeof(w));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)
        {
            scanf("%d%d",&w[i],&v[i]);
            s[w[i]][v[i]]++;
        }
        int k=0;
        for(int i=1;i<=10;++i)
        {
            for(int j=1;j<=10;++j)
            {
                if(s[i][j])
                {
                    for(int p=0;(1<<p)<s[i][j];p++)
                    {
                        k++;
                        w[k]=i*(1<<p);
                        v[k]=j*(1<<p);
                        s[i][j]-=(1<<p);
                    }
                    if(s[i][j])
                    {
                        k++;
                        w[k]=s[i][j]*i;
                        v[k]=s[i][j]*j;
                    }
                }
            }
        }
        for(int i=1;i<=k;++i)
        {
            for(int j=m;j>=w[i];--j)
                f[j]=max(f[j],f[j-w[i]]+v[i]);
        }
        printf("%d\n",f[m]);
    }
    return 0;
}