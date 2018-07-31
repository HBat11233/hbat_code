#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

#define INF 1005

using namespace std;

struct ips
{
    int w;
    int s;
    bool operator <(const ips &b)const
    {
        if(s==b.s)return w<b.w;
        else return s>b.s;
    }
}que[INF];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int t;
    scanf("%d",&t);
    for(int o=1;o<=t;++o)
    {
        map<int,bool>book;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",&que[i].w);
        for(int i=0;i<n;++i)
            scanf("%d",&que[i].s);
        sort(que,que+n);
        int ans=0;
        for(int i=0;i<n;++i)
        {
            int j=que[i].w;
            while(j)
            {
                if(!book[j])
                {
                    book[j]=true;
                    break;
                }
                j--;
            }
            if(j==0)ans+=que[i].s;
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
1 4 3 2 3 2 2 1 
9 8 7 6 5 4 3 2 
*/