#include <iostream>
#include <cstring>
#include <queue>


using namespace std;

int bfs(int bx,int by,int ex,int ey)
{
    const int dx[8]={2,-2,2,-2,-1,1,-1,1};
    const int dy[8]={1,1,-1,-1,2,2,-2,-2};
    int step[8][8];
    bool io[8][8];
    queue <int> qx,qy;
    memset(step,0,sizeof(step));
    memset(io,0,sizeof(io));
    qx.push(bx);
    qy.push(by);
    while(!qx.empty())
    {
        if(qx.front()==ex&&qy.front()==ey)
            return step[ex][ey];
        int x,y;
        for(int i=0;i<8;++i)
        {
            x=qx.front()+dx[i];
            y=qy.front()+dy[i];
            if(x>=0&&x<8&&y>=0&&y<8&&!io[x][y])
            {
                qx.push(x);
                qy.push(y);
                io[x][y]=true;
                step[x][y]=step[qx.front()][qy.front()]+1;
            }
        }
        qx.pop();
        qy.pop();
    }
    return step[ex][ey];
}

int main()
{
    freopen("text.txt","r",stdin);
    freopen("out.txt","w",stdout);
    char bx,by,ex,ey;
    while(~scanf("%c%c %c%c\n",&bx,&by,&ex,&ey))
    {
        int ans=bfs(int(bx-'a'),int(by-'1'),int(ex-'a'),int(ey-'1'));
        printf("To get from %c%c to %c%c takes %d knight moves.\n",bx,by,ex,ey,ans);
    }
    return 0;
}