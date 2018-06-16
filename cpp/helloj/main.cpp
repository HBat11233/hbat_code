#include <bits/stdc++.h>

using namespace std;

int n,m;
vector< vector <int> >com;
vector<int>ind;
vector<int>team;
int num=1;

int dfs(bool fte,int This)
{
    if(com[This].size()==0)
    {
        if(fte)team[This]=++num;
        else team[This]=num;
        return 0;
    }
    for(int i=0;i<com[This].size();++i)
    {
        if(team[com[This][i]]==0)
    }
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        com.resize(n+1);
        ind.resize(n+1);
        team.resize(n+1);
        int ta,tb;
        for(int i=0;i<m;++i)
        {
            scanf("%d%d",&ta,&tb);
            com[ta].push_back(tb);
            ind[tb]++;
        }
        com.clear();
        ind.clear();
        team.clear();
        num=1;
    }
    return 0;
}
