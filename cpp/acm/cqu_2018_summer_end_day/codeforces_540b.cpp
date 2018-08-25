#include <bits/stdc++.h>

#define INF 1000

using namespace std;

int ma[INF];
int ans[INF];

int main()
{
    int n,k,p,x,y;
    while(cin>>n>>k>>p>>x>>y)
    {
        int sum=0;
        for(int i=0;i<k;++i)
        {
            cin>>ma[i];
            sum+=ma[i];
        }
        if(sum+(n-k)>x)cout<<-1<<endl;
        else
        {
            int stnum = x-sum-(n-k);
            for(int i=k;i<n;++i)
                ma[i]=1;
            for(int i=k;i<n&&stnum>0;++i)
            {
                while(ma[i]<y&&stnum>0)
                {
                    ma[i]++;
                    stnum--;
                }
            }
            for(int i=0;i<n;++i)ans[i]=ma[i];
            sort(ma,ma+n);
            if(ma[n/2]<y)cout<<-1;
            else
                for(int i=k;i<n;++i)
                    cout<<ans[i]<<' ';
            cout<<endl;
        }
    }
    return 0;
}