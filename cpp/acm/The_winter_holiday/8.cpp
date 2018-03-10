//poj3050
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int hots[5][5];
map <int,bool> pk;
int ans;

int dfs(int x,int y,int le,int sum)
{
    if(le==6)
    {
        if(pk.count(sum)==0)
        {
            ans++;
            pk[sum]=true;
        }
        return 0;
    }
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    for(int i=0;i<4;++i)
    {
        int x1=x+dx[i];
        int y1=y+dy[i];
        if(x1>=0&&x1<5&&y1>=0&&y1<5)
            dfs(x1,y1,le+1,sum*10+hots[x1][y1]);
    }
    return 0;
}

int main()
{
    for(int i=0;i<5;++i)
        for(int j=0;j<5;++j)
            scanf("%d",*(hots+i)+j);
    ans=0;
    for(int i=0;i<5;++i)
    {
        for(int j=0;j<5;++j)
        {
            dfs(i,j,0,0);
        }
    }
    cout<<ans;
    //system("pause");
    return 0;
}