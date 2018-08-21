//生日悖论
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int o=1;o<=t;++o)
    {
        double n;
        double sum=1;
        int ans=0;
        cin>>n;
        for(double i=n;i>0;--i)
        {
            sum*=i/n;
            if(1-sum>=0.5)break;
            ans++;
        }
        cout<<"Case "<<o<<": "<<ans<<endl;

    }
    return 0;
}