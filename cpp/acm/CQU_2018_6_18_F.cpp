//拓扑排序，超时
#include <bits/stdc++.h>

using namespace std;

int d[100005];

void Dfind(vector <int> & q,int a,int b,int e)
{
    if(q[b]==a)q.erase(q.begin()+b);
    else if(q[e]==a)q.erase(q.begin()+e);
    else
    {
        int z=(b+e)/2;
        if(a<=q[z])Dfind(q,a,b,z);
        else Dfind(q,a,z,e);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(d,0,sizeof(d));
        int n;
        scanf("%d",&n);
        vector< vector <int> >que(n+1);
        int a,b;     
        for(int i=1;i<n;++i)
        {
            scanf("%d%d",&a,&b);
            d[a]++;
            d[b]++;
            que[a].push_back(b);
            que[b].push_back(a);
        }
        int num=n;
        int ans=0;
        vector <int> ml(n+1);
        for(int i=1;i<=n;++i)
            ml[i]=i;
        while(num!=1&&num!=0)
        {
            ans+=2;
            int tq[100005];
            int head=0;
            for(int i:ml)
            {
                if(d[i]==1)
                {
                    tq[head]=i;
                    head++;
                }
            }
            for(int j=0;j<head;++j)
            {
                Dfind(ml,tq[j],0,ml.size()-1);
                for(int k:que[tq[j]])
                    d[k]--;
            }
            num-=head;
        }
        if(num==0)ans-=1;
        printf("%d\n",ans);                                                                                                       
    }
    return 0;
}