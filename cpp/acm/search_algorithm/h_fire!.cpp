#include <iostream>
#include <queue>
#include <vector>
#define XYS b.x>=1 && b.x<=r && b.y>=1 && b.y<=c && domap[b.x][b.y]!='#' && domap[b.x][b.y]!='F'

using namespace std;

struct ip
{
    int x,y;
    ip(int a=0,int b=0):x(a),y(b){};
};

inline int funhbat()
{
    int r,c;
    const int dx[4]={1,0,-1,0};
    const int dy[4]={0,-1,0,1};
    queue <ip> quef,quej;
    ip J;
    scanf("%d %d\n",&r,&c);
    vector < vector <char> > domap(r+1,vector <char>(c+1,0));
    vector < vector <int> > length(r+1,vector <int>(c+1,0));
    for(int i=1;i<=r;++i)
    {
        for(int j=1;j<=c;++j)
        {
            scanf("%c",&domap[i][j]);
            if(domap[i][j]=='F')
            {
                ip a(i,j);
                quef.push(a);
            }
            else if(domap[i][j]=='J')
            {
                J.x=i;
                J.y=j;
                quej.push(J);
                length[i][j]=1;
            }
        }
        getchar();
    }
    while(!quej.empty())
    {
        int len=quef.size();
        for(int i=0;i<len;++i)
        {
            ip a=quef.front();
            for(int j=0;j<4;++j)
            {
                ip b(a.x+dx[j],a.y+dy[j]);
                if(XYS)
                {
                    quef.push(b);
                    domap[b.x][b.y]='F';
                }
            }
            quef.pop();
        }
        int i,lenj=quej.size();
        for(i=0;i<lenj;++i)
        {
            ip a=quej.front();
            int j;
            for(j=0;j<4;++j)
            {
                ip b(a.x+dx[j],a.y+dy[j]);
                if(XYS && domap[b.x][b.y]!='J')
                {
                    length[b.x][b.y]=length[a.x][a.y]+1;
                    quej.push(b);
                    domap[b.x][b.y]='J';
                    if(b.x==1||b.x==r||b.y==1||b.y==c)
                        return length[b.x][b.y];
                }
            }
            quej.pop();
        }
    }
    return 0;
}

int main()
{
    freopen("text.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n;
    scanf("%d\n",&n);
    while(n--)
        if(int a=funhbat())cout<<a<<endl;
        else cout<<"IMPOSSIBLE\n";
    return 0;
}
