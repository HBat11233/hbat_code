#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    int mon[12];
    cin>>k;
    for(int i=0;i<12;++i)
        cin>>mon[i];
    sort(mon,mon+12);
    int sum=0;
    int ans=0;
    while(sum<k&&ans<12)
        sum+=mon[11-ans++];
    if(ans>=12&&sum<k)ans=-1;
    cout<<ans<<endl;
    return 0;
}