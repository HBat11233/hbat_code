#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int o=1;o<=t;++o)
    {
        cout<<"Case "<<o<<": ";
        int n;
        cin>>n;
        double que[102];
        for(int i=0;i<n;++i)
            cin>>que[i];
        for(int i=n-2;i>=0;--i)
        {
            int len=0;
            double sum=0;
            for(int j=1;j<=6;++j)
            {
                if(i+j>=n)break;
                sum+=que[i+j];
                len++;
            }
            sum/=len;
            que[i]+=sum;
        }
        cout<<setprecision(7)<<fixed<<que[0]<<endl;
    }
    return 0;
}