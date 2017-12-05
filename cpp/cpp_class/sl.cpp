#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib> 
#include <queue>

using namespace std;

class sls
{
public:
    //sls(){sls(10,10);}
    sls(int ma=10,int num=10);                                                              //建立游戏
    int print();                                                                            //输出
    int fsls(int x,int y);                                                                  //挖雷
private:
    int n;                                                                                  //n*n的棋盘
    int num;                                                                                //雷数
    vector < vector <bool> > lq;                                                            //0无雷，1有雷
    vector < vector <int> > htl;                                                            //每一点的雷数
    vector < vector <bool> > seel;                                                          //输出列表,0为未打开
};

int sls::fsls(int x,int y)
{
    if(lq[x][y])
    {
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                seel[i][j]=1;
        return 1;
    }
    else if(htl[x][y]==0)                                                                   //bfs排雷
    {
        seel[x][y]=1;
        queue <int>qx,qy;
        qx.push(x);
        qy.push(y);
        while(qx.size())
        {
            int dx[8]={0,1,0,-1,1,1,-1,-1};
            int dy[8]={1,0,-1,0,-1,1,1,-1};
            for(int k=0;k<8;++k)
            {
                int x=qx.front()+dx[k];
                int y=qy.front()+dy[k];
                if(x>=0&&y>=0&&x<n&&y<n)
                {
                    if(htl[x][y]==0&&!seel[x][y])
                    {
                        qx.push(x);
                        qy.push(y);
                    }
                    seel[x][y]=1;
                }
            }
            qx.pop();
            qy.pop();
        }   
    }
    else
        seel[x][y]=1;
    return 0;
}

sls::sls(int ma,int nums)                                                                   //建立游戏
{
    srand(time(NULL));
    n=ma;
    num=nums;
    vector <bool> a(n,false);
    vector <int> b(n,0);
    for(int i=0;i<ma;++i)
    {
        lq.push_back(a);
        htl.push_back(b);
        seel.push_back(a);
    }
    for(int i=0;i<num;++i)                                                                  //随机雷
    {
        int x;
        int y;
        do
        {
            x=rand()%n;
            y=rand()%n;
        }while(lq[x][y]);
        lq[x][y]=true;
        htl[x][y]=9;
    }
    for(int i=0;i<n;++i)                                                                    //每个点周围的雷数
    {
        for(int j=0;j<n;++j)
        {
            if(lq[i][j])continue;
            int dx[8]={0,1,0,-1,1,1,-1,-1};
            int dy[8]={1,0,-1,0,-1,1,1,-1};
            for(int k=0;k<8;++k)
            {
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0&&y>=0&&x<n&&y<n&&lq[x][y])htl[i][j]++;
            }
        }
    }
}

int sls::print()
{
    int ans=0;                                                                              //剩余面积
    printf(" ");
    for(int i=0;i<n;++i)
        printf(" %d",i);
    cout<<endl;
    for(int i=0;i<n;++i)
    {
        printf("%d ",i);
        for(int j=0;j<n;++j)
            if(seel[i][j])printf("%d ",htl[i][j]);
            else 
            {
                ans++;
                printf("* ");
            }
        cout<<endl;
    }
    return ans;
}

int main()
{
    A1:
    int n,m;
    cout<<"n*n! -> n=";
    cin>>n;
    cout<<"bomb number:";
    cin>>m;
    sls ps(n,m);
    while(1)
    {
        if(ps.print()==m)
        {
            cout<<"Victory!\n";
            system("pause");
            cout<<' ';
            system("cls");
            goto A1;                                                                       //重新开始
        }
        int x,y;
        cout<<"Input:number1 number2\n:";
        cin>>x>>y;
        if(ps.fsls(x,y))
        {
            cout<<"game over\n";
            ps.print();
            system("pause");
            cout<<" ";
            system("cls");
            goto A1;                                                                        //重新开始
        }
        cout<<' ';
        system("cls");
    }
    system("pause");
    return 0;
}