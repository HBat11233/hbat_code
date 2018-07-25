#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d\n",&n,&m);
        char arr[n][m];
        int sum=0;
        int ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                scanf("%c",&arr[i][j]);
                if(arr[i][j]=='1')sum++;
                if(arr[i][j]=='0'&&(i==0||i==n-1||j==0||j==m-1))ans++;
            }
            getchar();
        }
        if(sum<((n+m)*2-4))cout<<-1<<'\n';
        else cout<<ans<<'\n';
    }
    return 0;
}