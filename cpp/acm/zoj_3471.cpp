#include <iostream>
#include <cstdio>

using namespace std;

int dp[15][15];
int maps[15][15];
int n;

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>maps[i][j];
    }
    return 0;
}