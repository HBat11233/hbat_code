#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#include <map>
#include <string>
#include <vector>

using namespace std;

int number=0;
char maps[21][21];          //地图
bool pbmap[21][21];         //箱子的可走路径

struct IP
{
    int x;
    int y;
    IP(const int x=-1,const int y=-1):
        x(x),y(y){}
    IP operator +(const IP &a)
    {
        IP ans(x+a.x,y+a.y);
        return ans;
    }
    IP operator -(const IP &a)
    {
        IP ans(x-a.x,y-a.y);
        return ans;
    }
    IP operator -()
    {
        return IP(-x,-y);
    }
    bool operator <(const IP &a)const
    {
        int i=x*100+y;
        int j=a.x*100+a.y;
        return i<j;
    }
    bool operator ==(const IP &a)const
    {
        return (x==a.x&&y==a.y);
    }
};

const IP dip[4]={IP(0,1),IP(1,0),IP(0,-1),IP(-1,0)};
const char wss[2][4]={{'e','s','w','n'},{'E','S','W','N'}};

map<IP,IP>last;
vector< map<IP,IP> > prm;
map<IP,int>prmpos;
map<IP,IP>tempt;

inline bool pq(IP &a,int &n,int &m)//判断范围
{
    return (a.x<n&&a.x>=0&&a.y<m&&a.y>=0);
}

bool cfs(IP &b,IP &e,IP &box,int &n,int &m)//判断当前位置人是否可以来
{
    map<IP,IP>plast;
    queue<IP>que;
    que.push(b);
    plast[b]=IP();
    bool psmap[21][21];
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(maps[i][j]=='#')psmap[i][j]=true;
            else psmap[i][j]=false;
    psmap[box.x][box.y]=true;
    if(psmap[e.x][e.y])return false;
    while(!que.empty())
    {
        IP head=que.front();
        for(int i=0;i<4;++i)
        {
            IP temp=head+dip[i];
            if(!pq(temp,n,m))continue;
            if(temp==e)
            {
                plast[temp]=head;
                prm.push_back(plast);
                return true;
            }
            if(!psmap[temp.x][temp.y])
            {
                que.push(temp);
                plast[temp]=head;
            }
        }
        que.pop();
        psmap[head.x][head.y]=true;
    }
    return false;
}

void printp(IP &T,int &pos)
{
    if(prm[pos][T]==IP())return;
    printp(prm[pos][T],pos);
    for(int i=0;i<4;++i)
    {
        if(prm[pos][T]+dip[i]==T)
        {
            printf("%c",wss[0][i]);
            break;
        }
    }
    return;
}

void print(IP &S,IP &B,IP &T)
{
    //if(S==T)return;
    bool k=true;
    if(!(S==last[T]&&T==B))print(S,B,last[T]);
    else k=false;
    if(prmpos.count(T))printp(tempt[T],prmpos[T]);
    for(int i=0;i<4&&k;++i)
    {
        if(last[T]+dip[i]==T)
        {
            printf("%c",wss[1][i]);
            break;
        }
    }
    return;
}

int box(int &n,int &m)
{
    number++;
    printf("Maze #%d\n",number);
    IP S,B,T;
    //初始化
    last.clear();
    prm.clear();
    prmpos.clear();
    tempt.clear();
    for(int i=0;i<21;++i)
        for(int j=0;j<21;++j)
        {
            maps[i][j]=0;
            pbmap[i][j]=false;
           // psmap[i][j]=false;
        }
    //输入
    string str;
    for(int i=0;i<n;++i)
    {
        getchar();
        for(int j=0;j<m;++j)
        {
            scanf("%c",*(maps+i)+j);
            switch(maps[i][j])
            {
                case 'S':
                    S.x=i,S.y=j;
                    break;
                case 'B':
                    B.x=i,B.y=j;
                    pbmap[i][j]=true;   //箱子已经走过的
                    break; 
                case 'T':
                    T.x=i,T.y=j;
                    break;
                case '#':                //墙
                    pbmap[i][j]=true;
                  //  psmap[i][j]=true;
            }
        }
    }
    
    //bfs box
    queue<IP>que;
    que.push(B);
    last[B]=S;
    while(!que.empty())
    {
        IP head=que.front();
        for(int i=0;i<4;++i)
        {
            bool k=false;
            IP temp,ftemp;
            temp=head+dip[i];
            ftemp=head-dip[i];
            if(!pq(temp,n,m)||!pq(ftemp,n,m))continue;
            if(temp==T)
            {
                last[temp]=head;
                print(S,B,T);
                cout<<endl<<endl;
                return 0;
            }
            if(!pbmap[temp.x][temp.y]&&(ftemp==last[head]||(k=cfs(last[head],ftemp,head,n,m))))
            {
                pbmap[temp.x][temp.y]=true;
                last[temp]=head;
                if(k)
                {
                    tempt[temp]=ftemp;
                    prmpos[temp]=prm.size()-1;
                }
                que.push(temp);  
            }
        }
        que.pop();
    }
    cout<<"Impossible."<<endl<<endl;
    return 0;
}

int main()
{
    int n,m;
    while(cin>>n>>m,n)
        box(n,m);
    return 0;
}
