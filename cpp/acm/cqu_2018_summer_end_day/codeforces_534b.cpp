#include <bits/stdc++.h>

using namespace std;

int vd[105];
int vk[105];

int main()
{
    int v1,v2;
    int t,d;
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    while(cin>>v1>>v2>>t>>d)
    {
        int ans=0;
        memset(vd,0,sizeof(vd));
        memset(vk,0,sizeof(vk));
        vd[0]=v1;
        for(int i=1;i<t;++i)
            vd[i]=vd[i-1]+d;
        vk[t-1]=v2;
        for(int i=t-2;i>=0;--i)
            vk[i]=vk[i+1]+d;
        for(int i=0;i<t;++i)
            ans+= vd[i]<vk[i]? vd[i]:vk[i];
        cout<<ans<<endl;
    }
    return 0;
}