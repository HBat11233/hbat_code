#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int bfs()
{
    int m,n,k,kmap[21][21],leng[21][21];
    bool maps[21][21],omap[21][21];
    memset(maps,0,sizeof(maps));                                    //初始化
    memset(omap,0,sizeof(omap));                                        
    memset(kmap,0,sizeof(kmap));
    memset(leng,0,sizeof(leng));
    cin>>m>>n>>k;
    queue <int> qx,qy;
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            cin>>maps[i][j];
    qx.push(1);                                                     //对首入队 
    qy.push(1);
    omap[1][1]=true;
    int dx[4]={0,1,0,-1};
     int dy[4]={1,0,-1,0};
    while(!qx.empty())
    {
        int x,y;
        if(qx.front()==m&&qy.front()==n)                                          //如果到达就输出
        {
            cout<<leng[qx.front()][qy.front()]<<endl;
            return 0;
        }
        for(int i=0;i<4;++i)
        {
            x=qx.front()+dx[i];
            y=qy.front()+dy[i];
            if(x<=m&&x>0&&y<=n&&y>0&&!omap[x][y])                   //是否在地图内，并且没有进入过
            {
                if(!maps[x][y])                                     //如果没有障碍物
                {
                    qx.push(x);                                     //入队
                    qy.push(y);
                    omap[x][y]=true;                                //标记入队
                    leng[x][y]=leng[qx.front()][qy.front()]+1;      //记录路程
                }
                else if(kmap[qx.front()][qy.front()]<k)             //否则有障碍物，跨过障碍物数是否小于k
                {
                    if(!kmap[x][y]||kmap[x][y]>kmap[qx.front()][qy.front()]+1)  //注意：墙不能入队，也不能每次都入，只有新路径比旧路径的穿墙数少时才可以
                    {
                        qx.push(x);                                     //入队
                        qy.push(y);
                  //    omap[x][y]=true;                                //标记入队
                        kmap[x][y]=kmap[qx.front()][qy.front()]+1;      //增加连续障碍数
                        leng[x][y]=leng[qx.front()][qy.front()]+1;      //记录路程
                    }
                }
            }
        }
        qx.pop();                                                   //出队
        qy.pop();                                                   //出队
    }
    cout<<-1<<endl;
    return 0;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
        bfs();
//  system("pause");
    return 0;
}