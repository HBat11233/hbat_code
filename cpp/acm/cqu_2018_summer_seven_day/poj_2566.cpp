#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

#define INF 1000005

using namespace std;

struct ips
{
    long long num;
    int pos;
    bool operator <(const ips &b)const 
    {
        if(num==b.num)pos<b.pos;
        return num<b.num;
    }
}que[INF];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int n,k;
    while(scanf("%d%d",&n,&k),n+k)
    {
        que[0].num=que[0].pos=0;
        for(int i=1;i<=n;++i)
        {
            int temp;
            scanf("%d",&temp);
            que[i].num=que[i-1].num+temp;
            que[i].pos=i;
        }
        sort(que,que+n+1);
        for(int o=0;o<k;++o)
        {
            long long tm;
            scanf("%lld",&tm);
            long long mins=0x7ffffffffffffff;
            long long ans;
            int l,r;
            for(int i=1,j=0;i<=n;++i)
            {
                while(j+1<i&&abs(que[i].num-que[j].num-tm)>=abs(que[i].num-que[j+1].num-tm))
                    j++;
                if(abs(que[i].num-que[j].num-tm)<mins)
                {
                    mins=abs(que[i].num-que[j].num-tm);
                    ans=que[i].num-que[j].num;
                    l=min(que[i].pos,que[j].pos)+1;
                    r=max(que[i].pos,que[j].pos);
                    if(!mins)break;
                }
            }
            printf("%lld %d %d\n",ans,l,r);
        }
    }
    return 0;
}