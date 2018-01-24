#include <iostream>
#include <cmath>
#include <queue>
#include <cstdio>

using namespace std;

int number=0;
int maps[201][2];
int dis[201];
bool k[201];

int w(int a,int b)
{
    return (pow((maps[a][0]-maps[b][0]),2)+pow((maps[a][1]-maps[b][1]),2));
}

int main()
{
    //freopen("1.txt","w",stdout);
    int n;
    while(scanf("%d",&n),n)
    {
        number++;
        for(int j=0;j<201;++j)
        {
            k[j]=false;
            dis[j]=0x7fffffff;
            for(int i=0;i<2;++i)
            {
                maps[j][i]=0;
            }
        }
        dis[0]=0;
        if(n==1)dis[1]=0;
        for(int i=0;i<n;++i)
            scanf("%d%d",*(maps+i),*(maps+i)+1);
        queue<int>que;
        que.push(0);
        k[0]=true;
        while(!que.empty())
        {
            int head=que.front();
            que.pop();
            k[head]=false;
            for(int i=0;i<n;++i)
            {
                if(i==head)continue;
                int temp;
                if((temp=max(dis[head],w(head,i)))<dis[i])
                {
                    dis[i]=temp;
                    if(!k[i])
                    {
                        que.push(i);
                        k[i]=true;
                    }
                }
            }
        }
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",number,sqrt(dis[1]));
    }
    return 0;
}

//wa,he wo mei guan xi