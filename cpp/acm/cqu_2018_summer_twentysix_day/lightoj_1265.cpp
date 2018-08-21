#include <iostream>
#include <iomanip>
#include <cstring>

#define INF 1002

using namespace std;

double sol(double t,double d)
{
    if(int(t)%2)return 0;
    else if(t==0)return 1;
    return 1/(t+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int o=1;o<=T;++o)
    {
        int t,d;
        cin>>t>>d;
        cout<<"Case "<<o<<": "<<setprecision(7)<<fixed<<sol(t,d)<<endl;
    }
    return 0;
}