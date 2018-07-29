#include <bits/stdc++.h>

using namespace std;
struct ipd
{
    int pos;
    int num;
    bool operator <(const ipd &b)const
    {
        return num>b.num;
    }
}que[300005];

struct mmp
{
    int a;
    int b;
    mmp(int a=0,int b=0)
    :a(a),b(b){}
    bool operator < (const mmp &c)const
    {
        if(a==c.a)return b<c.b;
        else return a<c.a;
    }
}cm[300005];

int c[300005];
int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int n,p;
    c[1]=0;
    c[2]=1;
    for(int i=2;i<300004;++i)
        c[i+1]=i+c[i];
    while(~scanf("%d%d",&n,&p))
    {
        for(int i=0;i<=n;++i)
            que[i].num=0;
        map<mmp,int>book;
        for(int i=0;i<n;++i)
        {
            mmp tp;
            scanf("%d%d",&tp.a,&tp.b);
            que[tp.a].num++;
            que[tp.a].pos=tp.a;
            que[tp.b].num++;
            que[tp.b].pos=tp.b;
            book[tp]++;
            cm[i]=tp;
        }
        int ans=0;
        map<mmp,bool>pk;
        for(int i=0;i<n;++i)
            if(!pk[mmp(cm[i].a,cm[i].b)])
            if(que[cm[i].a].num>=p&&que[cm[i].b].num>=p)
            {
                pk[mmp(cm[i].a,cm[i].b)]=pk[mmp(cm[i].b,cm[i].a)]=true;
                int temp=que[cm[i].a].num+que[cm[i].b].num-book[mmp(cm[i].a,cm[i].b)]-book[mmp(cm[i].b,cm[i].a)];
                if(temp<p)
                ans--;
            }
        sort(que+1,que+n+1);
        int A=0;
        for(int i=1;i<=n;++i)
            if(que[i].num<p)break;
            else A++;
        ans+=c[A];
        for(int i=n;i>1;--i)
        {
            if(que[i].num>=p)break;
            for(int j=1;j<i;++j)
            {
                int temp=que[i].num+que[j].num;
                if(temp-book[mmp(que[i].pos,que[j].pos)]-book[mmp(que[j].pos,que[i].pos)]>=p)ans++;
                else if(temp<p)break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}