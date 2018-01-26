#include <algorithm>
#include <iostream>

using namespace std;

int f[100020];
int ned[505];
int vid[505];

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>ned[i]>>vid[i];
    for(int i=1;i<=n;++i)
        for(int j=m;j>=ned[i];--j)
            f[j]=max(f[j],f[j-ned[i]]+vid[i]);
    cout<<f[m];
    return 0;
}