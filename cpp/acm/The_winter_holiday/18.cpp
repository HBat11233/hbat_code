//aizu 0189
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

int map[11][11];
int n;

int main()
{
    while(scanf("%d",&n),n)
    {
        int maxs=-1;
        for(int i=0;i<10;++i)
            for(int j=0;j<10;++j)
                map[i][j]=45000;
        for(int i=0;i<10;++i)
            map[i][i]=0;
        for(int i=0;i<n;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            scanf("%d",&map[a][b]);
            map[b][a]=map[a][b];
            maxs=max(a,max(b,maxs));
        }
        for(int k=0;k<=maxs;++k)
            for(int i=0;i<=maxs;++i)
                for(int j=0;j<=maxs;++j)
                {
                    if(i==j||j==k||i==k)continue;
                    map[i][j]=min(map[i][k]+map[k][j],map[i][j]);
                }
        int ans1,ans2=0x7fffffff;
        for(int i=0;i<=maxs;++i)
        {
            int temp1=0;
            for(int j=0;j<=maxs;++j)
                temp1+=map[i][j];
            if(temp1<ans2)
            {
                ans1=i;
                ans2=temp1;
            }
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}