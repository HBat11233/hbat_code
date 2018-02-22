//poj3187
#include <iostream>
#include <cstdio>

using namespace std;

int n,r;
bool row[11];
int ans[11];
int qjz[11][11]=
{
    {},
    {1},
    {1,1},
    {1,2,1},
    {1,3,3,1},
    {1,4,6,4,1},
    {1,5,10,10,5,1},
    {1,6,15,20,15,6,1},
    {1,7,21,35,35,21,7,1},
    {1,8,28,56,70,56,28,8,1},
    {1,9,36,84,126,126,84,36,9,1}
};
bool sb=false;

int dfs(int st)
{
    if(sb)return 0;
    if(st==n)
    {
        int sum=0;
        for(int i=0;i<n;++i)
            sum+=qjz[n][i]*ans[i];
        if(sum==r)
        {
            sb=true;
            return 0;
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(row[i])continue;
        row[i]=true;
        ans[st]=i;
        dfs(st+1);
        if(sb)return 0;
        row[i]=false;
    }
    return 0;
}

int main()
{
    scanf("%d%d",&n,&r);
    dfs(0);
    for(int i=0;i<n;++i)
        printf("%d ",ans[i]);
    return 0;
}