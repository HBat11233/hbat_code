#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n,m;
vector<int>que;
int f[100005];
int pt[100005];

int find(int x)
{
    if(x!=f[x])
        f[x]=find(f[x]);
    return f[x];
}

int main()
{
    int a,b;
    bool p=false;
    for(int i=0;i<100005;++i)
        f[i]=i,pt[i]=false;
    while((scanf("%d%d",&a,&b)),(~a&&~b))
    {
        if(a==0&&b==0)
        {
            if(!p)
            {
                int x=find(que[0]);
                for(int i=0;i<que.size();++i)
                    if(x!=find(que[i]))
                    {
                        p=true;
                        cout<<"No\n";
                        break;
                    }
            }
            if(!p)cout<<"Yes\n";
            for(int i=0;i<100005;++i)
                f[i]=i,pt[i]=false;
            que.clear();
            p=false;
            continue;
        }
        if(p||a==b)continue;
        if(!pt[a])pt[a]=true,que.push_back(a);
        if(!pt[b])pt[b]=true,que.push_back(b);
        int x=find(a);
        int y=find(b);
        if(x==y)
            p=true,cout<<"No\n";
        else
            f[x]=y;
    }
    return 0;
}