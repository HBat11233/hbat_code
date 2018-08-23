//f(n)=ln(n)+c+1/2*n
//c=0.57721566490153286060651209
//n 很大的时候，公式近似
#include <bits/stdc++.h>

#define INF 10000 //公式可以接受的误差
#define C 0.57721566490153286060651209

using namespace std;

double book[INF];

double dfs(int x)
{
    for(int i=1;i<=x;++i)
    {
        if(book[i]!=0)continue;
        book[i]=book[i-1]+1.0/i;
    }
    return book[x];

}

int main()
{
    //freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    memset(book,0,sizeof(book));
    book[1]=1;
    int t;
    cin>>t;
    for(int o=1;o<=t;++o)
    {
        double ans;
        int n;
        cin>>n;
        if(n>=INF||book[n]==0)
        {
            if(n<INF)
                ans=dfs(n);
            else ans=log(n)+C+1.0/(2.0*n);
        }else ans=book[n];
        cout<<"Case "<<o<<": "<<setprecision(10)<<fixed<<ans<<endl;
    }
    return 0;
}