#include <bits/stdc++.h>

#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;

int c,s,d;
int w[105][105];

int main()
{
    int o=0;
    while(scanf("%d%d%d",&c,&s,&d),c+s+d)
    {
        mem(w,0x7f);
        for(int i=1;i<=c;++i)
            w[i][i]=0;
        for(int i=0;i<s;++i)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            w[a][b]=c;
            w[b][a]=c;
        }
        for(int k=1;k<=c;++k)
        {
            for(int i=1;i<=c;++i)
            {
                for(int j=1;j<=c;++j)
                {
                    if(w[i][j]>max(w[i][k],w[k][j]))
                        w[i][j]=max(w[i][k],w[k][j]);
                }
            }
        }
        if(o)printf("\n");
        printf("Case #%d\n",++o);
        for(int i=0;i<d;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(w[a][b]>=0x7f7f7f7)printf("no path\n");
            else printf("%d\n",w[a][b]);
        }
    }
    return 0;
}