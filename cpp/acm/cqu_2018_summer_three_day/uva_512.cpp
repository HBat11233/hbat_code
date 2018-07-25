#include <bits/stdc++.h>

using namespace std;

struct ips
{
    int r;
    int c;
    int pr;
    int oc;
    ips()
    :r(0),c(0){}
    void s()
    {
        pr=r;
        oc=c;
    }
};

struct com
{
    bool dr=0;
    bool dc=0;
    bool ic=0;
    bool ir=0;
    bool ex=0;
    int x,y,a,b;
    vector<int>que;
    ips tcmd(ips &a)
    {
        if(dr)
        {
            int sum=0;
            for(int i=0;i<que.size();++i)
                if(a.r>que[i])sum++;
                else if(a.r==que[i])
                {
                    a.r=-1,a.c=-1,sum=0;
                    break;
                }
            a.r-=sum;
        }
        else if(dc)
        {
            int sum=0;
            for(int i=0;i<que.size();++i)
                if(a.c>que[i])sum++;
                else if(a.c==que[i])
                {
                    a.r=-1,a.c=-1,sum=0;
                    break;
                }
            a.c-=sum;
        }
        else if(ic)
        {
            int sum=0;
            for(int i=0;i<que.size();++i)
                if(a.c>=que[i])sum++;
            a.c+=sum;
        }
        else if(ir)
        {
            int sum=0;
            for(int i=0;i<que.size();++i)
                if(a.r>=que[i])sum++;
            a.r+=sum;
        }
        else if(ex)
        {
            if(x==a.r&&y==a.c)a.r=this->a,a.c=b;
            else if(this->a==a.r&&b==a.c)a.r=x,a.c=y;
        }
        return a;
    }
};

int main()
{
    int r,c;
    int n,m;
    int nm=0;
    while(scanf("%d%d",&r,&c),r+c)
    {
        if(nm)printf("\n");
        scanf("%d",&n);
        vector<com>cmd;
        vector<ips>sea0;
        cmd.resize(n);
        for(int i=0;i<n;++i)
        {
            string str;
            cin>>str;
            int len=0;
                if(str=="DR")
                {
                    cmd[i].dr=1;
                    scanf("%d",&len);
                    cmd[i].que.resize(len);
                    for(int j=0;j<len;++j)
                        scanf("%d",&cmd[i].que[j]);
                }
                if(str=="DC")
                {
                    cmd[i].dc=1;
                    scanf("%d",&len);
                    cmd[i].que.resize(len);
                    for(int j=0;j<len;++j)
                        scanf("%d",&cmd[i].que[j]);
                }
                if(str=="IC")
                {
                    cmd[i].ic=1;
                    scanf("%d",&len);
                    cmd[i].que.resize(len);
                    for(int j=0;j<len;++j)
                        scanf("%d",&cmd[i].que[j]);
                }
                if(str=="IR")
                {
                    cmd[i].ir=1;
                    scanf("%d",&len);
                    cmd[i].que.resize(len);
                    for(int j=0;j<len;++j)
                        scanf("%d",&cmd[i].que[j]);
                }
                if(str=="EX")
                {
                    cmd[i]. ex=1;
                    scanf("%d%d%d%d",&cmd[i].x,&cmd[i].y,&cmd[i].a,&cmd[i].b);
                }
            
        }
        scanf("%d",&m);
        sea0.resize(m);
        for(int i=0;i<m;++i)
            scanf("%d%d",&sea0[i].r,&sea0[i].c),sea0[i].s();
        printf("Spreadsheet #%d\n",++nm);
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
                cmd[j].tcmd(sea0[i]);
            printf("Cell data in (%d,%d) ",sea0[i].pr,sea0[i].oc);
            if(sea0[i].r==-1&&sea0[i].c==-1)printf("GONE\n");
            else printf("moved to (%d,%d)\n",sea0[i].r,sea0[i].c);
        }
    }
    return 0;
}