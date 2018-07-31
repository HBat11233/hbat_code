#include <iostream>
#include <cstdio>
#include <cstring>

#define INF 100005

using namespace std;

bool pk[5005];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;++i)
        {
            char ch;
            getchar();
            scanf("%c",&ch);
            if(ch=='F')pk[i]=true;
            else pk[i]=false;
        }
        int m=0x7fffffff;
        int ans;
        int po[5005];
        
        for(int k=1;k<=n;++k)
        {
            memset(po,0,sizeof(po));
            int num=0;
            int sum=0;
            for(int i=0;i+k<=n;++i)
            {
                if(!pk[i]&&sum%2==0||pk[i]&&sum%2==1)
                {
                    sum++;
                    num++;
                    po[i]=true;
                }
                sum= i-k+1>=0&&po[i-k+1]? sum-1:sum;
            }
            bool ppi=false;
            for(int i=n-k+1;i<n;++i)
            {
                if(!pk[i]&&sum%2==0||pk[i]&&sum%2==1)
                {
                    ppi=true;
                    break;
                }
                sum= i-k+1>=0&&po[i-k+1]? sum-1:sum;
            }
            if(!ppi&&num<m)
            {
                m=num;
                ans=k;
            }
        }
        printf("%d %d\n",ans,m);
    }
    return 0;
}