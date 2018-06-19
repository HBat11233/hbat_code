#include <QCoreApplication>
#include <bits/stdc++.h>

using namespace std;
#define INF 100005
#define MEM(a,b) memset(a,b,sizeof(a))

int x[INF];
int y[INF];
int nexts[INF];
int frista[INF];
int len;

int bfs(int b)
{
    len=0;
    int last;
    queue<int>que;
    que.push(b);
    while(!que.empty())
    {
        last=que.front();
        int h=frista[last];
        while(h!=-1)
        {
            que.push(y[h]);
            h=nexts[h];
        }
        len++;
        que.pop();
    }
    return last;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        MEM(frista,-1);
        MEM(nexts,-1);
        for(int i=1;i<n;++i)
        {
            scanf("%d%d",x+i,y+i);
            nexts[i]=frista[x[i]];
            frista[x[i]]=i;
        }
        bfs(bfs(1));
        printf("%d\n",len);
    }
    return 0;
    return a.exec();
}
