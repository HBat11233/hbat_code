#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define MEST(a,b) memset(a,b,sizeof(a))

using namespace std;

struct ip
{
    int x,y;
    int length;
    ip():x(0),y(0),length(0){};
    bool operator == (const ip &a)
    {
        if(x==a.x&&y==a.y)return true;
        else return false;
    }
};

vector <ip> bfs(ip a,char maps[][201],int &n,int &m)
{
    vector <ip> ans;
    queue <ip> que;
    bool om[201][201];
    MEST(om,0);
    const int dx[4]={0,1,0,-1};
    const int dy[4]={1,0,-1,0};
    que.push(a);
    om[a.x][a.y]=true;
    while(!que.empty())
    {
        int x,y;
        ip temp=que.front();
        for(int i=0;i<4;++i)
        {
            x=temp.x+dx[i];
            y=temp.y+dy[i];
            if(x<1||x>n||y<1||y>m||om[x][y])continue;
            if(maps[x][y]=='.')
            {
                ip z;
                z.x=x;
                z.y=y;
                z.length=temp.length+1;
                om[x][y]=true;
                que.push(z);
            }
            else if(maps[x][y]=='@')
            {
                ip z;
                z.x=x;
                z.y=y;
                z.length=temp.length+1;
                om[x][y]=true;
                que.push(z);
                ans.push_back(z);
            }
        }
        que.pop();
    }
    return ans;
}
int main()
{
    freopen("text.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n,m;
    char maps[201][201];
    while(~scanf("%d%d",&n,&m))
    {
        getchar();
        MEST(maps,0);
        ip P,M;
        vector <ip> pa,ma;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;++j)
            {
                scanf("%c",&maps[i][j]);
                if(maps[i][j]=='Y'){P.x=i,P.y=j;}
                else if(maps[i][j]=='M'){M.x=i,M.y=j;}
            }
            getchar();
        }
        pa=bfs(P,maps,n,m);
        ma=bfs(M,maps,n,m);
        int temp=0x7fffffff;
        for(ip i:pa)
            for(ip j:ma)
                if(i==j)
                    temp=temp<(i.length+j.length)*11? temp:(i.length+j.length)*11;
        cout<<temp<<endl;
    }
    return 0;
}