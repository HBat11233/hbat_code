#include <iostream>
#include <cstdio>
#include <cstring>

#define INF 1000005

using namespace std;

int n;
char str[INF];
int nexts[INF];

int main()
{
    int o=0;
    while(scanf("%d",&n),n)
    {
        memset(nexts,0,sizeof(nexts));
        memset(str,0,sizeof(str));
        scanf("%s",str);
        nexts[0]=-1;
        for(int i=0,pos=-1;i<n;)
        {
            if(pos==-1||str[i]==str[pos])
            {
                nexts[++i]=++pos;
            }else
            {
                pos=nexts[pos];
            }
        }
        printf("Test case #%d\n",++o);
        for(int i=1;i<=n;++i)
        {
            if(nexts[i]==0)continue;
            if(i%(i-nexts[i])==0)
                printf("%d %d\n",i,i/(i-nexts[i]));
        }
        printf("\n");
    }
    return 0;
}