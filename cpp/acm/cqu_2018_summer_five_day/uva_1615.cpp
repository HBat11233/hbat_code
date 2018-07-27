#include <bits/stdc++.h>

using namespace std;

struct cityip
{
    int l;
    int r;
    void made(const int & d,const int &le,int x,int y)
    {
        int dt=sqrt(d*d-y*y);
        if(dt>=x)l=0;
        else l=x-dt;
        if(dt+x<le)r=dt+x;
        else r=le-1;
    }
    bool operator <(const cityip &b)const
    {
        if(r==b.r)return l>b.l;
        return r<b.r;
    }
};

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int l,d,n;
    while(~scanf("%d%d%d",&l,&d,&n))
    {
        vector<cityip>que(n);
        for(int i=0;i<n;++i)
        {
            int x,y;
            scanf("%d%d",&x,&y),que[i].made(d,l,x,y);
        }
        sort(que.begin(),que.end());
        int ans=1;
        int temp=que[0].r;
        for(int i=1;i<n;++i)
            if(temp<que[i].l)
            {
                ans++;
                temp=que[i].r;
            }
        printf("%d\n",ans);
        
    }
    return 0;
}