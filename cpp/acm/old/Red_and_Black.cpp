#include <iostream>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

vector < string > map;
int w,m;
int ans;

int dfs(int x,int y)
{
    int xg[4]={0,1,0,-1};
    int yg[4]={1,0,-1,0};
    for(int i=0;i<4;++i)
    {
        int x1=xg[i] + x,y1=yg[i] + y;
        if(y1<m && y1>=0 && x1>=0 && x1<w && map[y1][x1]=='.')
        {
            ans++;
            map[y1][x1]='#';
            dfs(x1,y1);
        }
    }
    return ans;
}

int main()
{
    while( cin>>w>>m )
    {
        if(w==0)return 0;
        map.resize(m);
        int x=0,y=0;
        for(int i=0;i<m;++i)
        {
            cin>>map[i];
            for(int j=0;j<w;++j)
                if(map[i][j]=='@')
                {
                    x=j;
                    y=i;
                    break;
                }
        }
        ans=1;
        cout<<dfs(x,y)<<endl;
        w=0,m=0;
    }
    return 0;
}