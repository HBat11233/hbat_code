#include <bits/stdc++.h>

using namespace std;

int p;


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,k;
        vector< vector <int> >c;
        scanf("%d%d%d%d",&n,&m,&k,&p);
        int temp=max(n,m);
        int temps=temp*k+5;
        c.resize(temps);
        for(int i=0;i<c.size();++i)
            c[i].resize(i+1);
        for(int i=0;i<temps;++i)
            c[i][0]=c[i][i]=1;
        for(int i=1;i<temps;++i)
            for(int j=1;j<i;++j)
                c[i][j]=(c[i-1][j-1]%p+c[i][j-1]%p)%p;
        int ans=0;
        temp=k/2;
        while(temp)
        {
            if(temp<=m&&(k-(temp<<1))<=n)
            {
                ans+=(c[m][temp]*c[n][k-(temp<<1)])%p;
                ans%=p;
            }
            temp--;
        }
        if(k<=n)
        {
            ans+=c[n][k];
            ans%=p;
        }
        printf("%d\n",ans);
    }
    return 0;
}