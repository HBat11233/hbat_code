//poj 2377
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n,m;
int d[1001];
int wss[1001][1001];
bool tr[1001];

struct TP
{
    int n;
    TP(int n=0):
        n(n){}
};

bool _comp(const TP &a,const TP &b)
{
    return d[a.n]<d[b.n];
}


map < int , vector <TP> >w;

int prim()
{
    vector<TP>que;
    tr[1]=true;
    for(int i=0;i<w[1].size();++i)
    {
        d[w[1][i].n]=wss[1][w[1][i].n];
        que.push_back(w[1][i]);
    }
    while(que.size())
    {
        sort(que.begin(),que.end(),_comp);
        TP a=*que.rbegin();
        tr[a.n]=true;
        que.pop_back();
        for(int i=0;i<w[a.n].size();++i)
        {
            if(tr[w[a.n][i].n])continue;
            if(d[w[a.n][i].n])d[w[a.n][i].n]=max(d[w[a.n][i].n],wss[a.n][w[a.n][i].n]);
            else
            {
                d[w[a.n][i].n]=wss[a.n][w[a.n][i].n];
                que.push_back(w[a.n][i]);
            }
        }
    }
    int ans=0;
    for(int i=2;i<=n;++i)
    {
        if(!tr[i])
        {
            ans=-1;
            break;
        }
        ans+=d[i];
    }
    return ans;
}

int main()
{
    //freopen("C:\\Users\\HBat\\Desktop\\2.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(wss[a][b]!=0)wss[b][a]=wss[a][b]=max(wss[a][b],c);
        else
        {
            w[a].push_back(TP(b));
            w[b].push_back(TP(a));
            wss[a][b]=wss[b][a]=c;
        }
    }
    cout<<prim()<<endl;
    return 0;
}