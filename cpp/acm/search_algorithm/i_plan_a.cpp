#include <iostream>
#include <cstring>

using namespace std;

struct ip
{
    int x,y,z;
    //ip():x(0),y(0),z(0){};
    ip(int a=0,int b=0,int c=0):x(a),y(b),z(c){};
    bool operator ==(const ip &a)
    {
        if(x==a.x&&y==a.y&&z==a.z)return true;
        else return false;
    } 
};
char map[11][11][2];
int length[11][11][2];
int km[11][11][2];
int n,m,t;

int dfs(ip temp,ip p)
{
    if(length[temp.x][temp.y][temp.z]>t)return 0;
    if(temp==p)
    {
        if(length[p.x][p.y][p.z]<=t)//如果小于，徘徊一下就够了
        {
            cout<<"YES\n";
            return 1;
        }
        return 0;
    }
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    for(int i=0;i<4;++i)
    {
        int x=temp.x+dx[i];
        int y=temp.y+dy[i];
        int z=temp.z;
        if(x>=1&&x<=n&&y>=1&&y<=m&&!km[x][y][z])
        {
            if(map[x][y][z]=='.'||map[x][y][z]=='P')
            {
                int tp=length[x][y][z];
                length[x][y][z]=length[temp.x][temp.y][temp.z]+1;
                km[x][y][z]++;
                ip a(x,y,z);
                if(dfs(a,p))return 1;
                length[x][y][z]=tp;
                km[x][y][z]--;
            }
            else if (map[x][y][z]=='#')
            {
                z=(z+1)%2;
                if(map[x][y][z]=='*'||map[x][y][z]=='#')z=(z+1)%2;
                else
                {
                    int tp=length[x][y][z];
                    length[x][y][z]=length[temp.x][temp.y][temp.z]+1;
                    km[x][y][z]++;
                    km[x][y][(z+1)%2]++;
                    ip a(x,y,z);
                    if(dfs(a,p))return 1;
                    km[x][y][z]--;
                    km[x][y][(z+1)%2]--;
                    length[x][y][z]=tp;
                    z=(z+1)%2;
                }
            }
        }
    }
    return 0;
}

inline int funk()
{
    ip s,p;
    memset(length,0,sizeof(length));
    memset(map,0,sizeof(map));
    memset(km,0,sizeof(km));
    scanf("%d %d %d",&n,&m,&t);
    for(int k=0;k<2;++k)
    {
        getchar();
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                scanf("%c",&map[i][j][k]);
                if(map[i][j][k]=='S'){s.x=i,s.y=j,s.z=k;}
                else if(map[i][j][k]=='P'){p.x=i,p.y=j,p.z=k;}
            }
            getchar();
        }
    }
    km[s.x][s.y][s.z]++;
    if(!dfs(s,p))cout<<"NO\n";
    return 0;
}

int main()
{
    freopen("text.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int c;
    scanf("%d",&c);
    while(c--)
        funk();
    return 0;
}