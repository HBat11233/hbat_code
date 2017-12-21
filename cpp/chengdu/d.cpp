#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    string a,b;
    cin>>n>>a>>b;
    int ans=0;
    for(int i=0;i<n;++i)
    {
        int temp=abs(a[i]-b[i]);
        ans+=min(temp,10-temp);
    }
    cout<<ans;
    return 0;
}