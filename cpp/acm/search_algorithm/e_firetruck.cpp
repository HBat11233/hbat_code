#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> road[22];
int ankr[22];
int ank[22];
vector < vector <int> > ans;
vector <int> temp;
int k=0;

int dfsr(int x)
{
    ankr[x]=true;
    for(int i=0;i<road[x].size();++i)
    {
        if(ankr[road[x][i]])continue;
        dfsr(road[x][i]);
    }
    return 0;
}

int dfs(int x,int &n)
{
    if(x==n)ans.push_back(temp);
    else for(int i=0;i<road[x].size();++i)
    {
        if(!ankr[road[x][i]]||ank[road[x][i]])continue;
        ank[road[x][i]]=true;
        temp.push_back(road[x][i]);
        dfs(road[x][i],n);
        temp.pop_back();
        ank[road[x][i]]=false;
    }
    return 0;
}

int func(int &n)
{
    memset(ankr,0,sizeof(ankr));
    memset(ank,0,sizeof(ank));
    for(int i=0;i<22;++i)
        road[i].clear();
    ans.clear();
    temp.clear();
    int i,j;
    k++;
    while(scanf("%d%d",&i,&j),i)
    {
        road[i].push_back(j);
        road[j].push_back(i);
    }
    dfsr(n);
    ank[1]=true;
    temp.push_back(1);
    dfs(1,n);
    sort(ans.begin(),ans.end());
    cout<<"CASE "<<k<<":\n";
    for(i=0;i<ans.size();++i)
    {
        int s=ans[i].size()-1;
        for(j=0;j<ans[i].size();++j)
        {
            cout<<ans[i][j];
            if(j==s)cout<<endl;
            else cout<<' ';
        }
    }
    printf("There are %d routes from the firestation to streetcorner %d.\n",ans.size(),n);
    
    return 0;
}

int main()
{
    int n;
    while(~scanf("%d",&n))
        func(n);
    return 0;
}
/*
6
1 2
1 3
3 4
3 5
4 6
5 6
2 3
2 4
0 0
4
2 3
3 4
5 1
1 6
7 8
8 9
2 5
5 7
3 1
1 8
4 6
6 9
0 0
*/