#include <iostream>
#include <cstring>
#include <cstdio>

#define INF 100005

using namespace std;

int n,m;
int num=0;
int maps[16][16];
int ans[16][16];
int tmaps[16][16];
int pans[16][16];
int len=0x7fffffff;

void fz(int a,int b)
{
    num++;
    ans[a][b]=1;
    tmaps[a][b]^=1;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    for(int i=0;i<4;++i)
    {
        int x=a+dx[i];
        int y=b+dy[i];
        if(x>=0&&x<n&&y>=0&&y<m)
            tmaps[x][y]^=1;  
    }
}

void print()
{
    printf("--------------\n");
    printf("--------------\n");
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            printf("%d ",tmaps[i][j]);
        }
        printf("\n");
    }
    printf("--------------\n");
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    printf("--------------\n");
    printf("--------------\n");
}

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    while(~scanf("%d%d",&n,&m))
    {
        memset(pans,0,sizeof(pans));
        memset(ans,0,sizeof(ans));
        len=0x7fffffff;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;j++)
                scanf("%d",&maps[i][j]);
        int j;
        bool pr=false;
            for(j=0;j< 1<<m;++j)
            {
                num=0;
                bool pk=false;
                memset(ans,0,sizeof(ans));
                memcpy(tmaps,maps,sizeof(tmaps));
                for(int k=m-1;k>=0;--k)
                    if(j&(1<<k))fz(0,m-k-1);
                for(int p=0;p<n-1;++p)
                {
                    for(int k=0;k<m;++k)
                    if(tmaps[p][k])fz(p+1,k);
                }
                for(int p=0;p<m;++p)
                    if(tmaps[n-1][p])pk=true;
                if(!pk)
                {
                    if(num<len)
                    {
                        pr=true;
                        len=num;
                        memcpy(pans,ans,sizeof(pans));
                    }
                }
            }
        if(pr)
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
                printf("%d ",pans[i][j]);
            printf("\n");
        }
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}