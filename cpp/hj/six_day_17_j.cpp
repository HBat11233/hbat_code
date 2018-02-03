#include <iostream>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <cstring>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int k=1;k<=n;++k)
    {
        int len;
        scanf("%d",&len);
        vector <double> que(len);
        for(int i=0;i<len;++i)
            scanf("%lf",&que[i]);
        double ans[200];
        memset(ans,0,sizeof(ans));
        for(int i=len-1;i>=0;--i)
        {
            int pos=0;
            for(int j=(i+1<len?i+1:len);j<(i+7<len? i+7:len);++j)
            {
                ans[i]+=ans[j];
                pos++;
            }
            if(pos)ans[i]/=pos;
            ans[i]+=que[i];
        }
        cout<<"Case "<<k<<": ";
        cout<<setprecision(7)<<fixed<<ans[0]<<endl;
    }
    return 0;
}