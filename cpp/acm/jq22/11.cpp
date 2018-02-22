//poj1631
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>w(n,0);
        for(int i=0;i<n;++i)
            cin>>w[i];
        vector<int>num(n,0x7fffffff);
        int ans=0;
        for(int i=0;i<n;++i)
        {
            int k = lower_bound(num.begin(),num.end(),w[i])-num.begin();
            ans = max(ans,k);
            num[k]=w[i];
        }
        cout<<ans+1<<endl;
    }
    return 0;
}