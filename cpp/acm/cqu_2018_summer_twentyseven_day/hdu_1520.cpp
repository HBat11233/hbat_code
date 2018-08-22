#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define INF 6004
#define mst(a,b) memset(a,b,sizeof(a))

using namespace std;

int dp[INF][2];
int fa[INF];
bool isson[INF];
vector <int> son[INF];
int root;

void dfs(int x)
{
    for(int i:son[x])
    {
        dfs(i);
        dp[x][1]+=dp[i][0];
        dp[x][0]+=max(dp[i][1],dp[i][0]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    while(cin>>n)
    {
        mst(dp,0);
        mst(fa,0);
        mst(isson,0);
        for(int i=0;i<INF;++i)
            son[i].clear();
        for(int i=1;i<=n;++i)
            cin>>dp[i][1];
        int l,k;
        while(cin>>l>>k,l|k)
        {
            fa[l]=k;
            son[k].push_back(l);
            isson[l]=true;
        }
        for(int i=1;i<=n;++i)
            if(!isson[i]){root=i;break;}
        dfs(root);
        cout<<max(dp[root][1],dp[root][0])<<endl;
    }
    return 0;
}