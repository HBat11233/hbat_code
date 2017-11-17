#include <iostream>
#include <cmath>

int t;
int h,m,s;

using namespace std;

int main()
{
    cin>>t;
    for(int i=0;i<t;++i)
    {
        cin>>h>>m>>s;
        h%=12;
        double mr=0.0,hr=0.0;
        mr=6.0*m+0.1*s;
        hr=30.0*h+0.5*m+s*(1.0/120.0);
        double ab=0.0;
        int ans=0;
        ab=fabs(hr-mr);
        if(ab>180)ans=360.0-ab;
        else ans=ab;
        cout<<ans<<endl;
    }
    return 0;
}
