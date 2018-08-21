#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin>>t;
    int o=0;
    while(t--)
    {
        int n;
        cin>>n;
        double ans=0;
        for(double i=1;i<=n;++i)
            ans+=(1/i);
        ans*=n;
        cout<<"Case "<<++o<<": "<<setprecision(7)<<fixed<<ans<<endl;
    }

    return 0;
}