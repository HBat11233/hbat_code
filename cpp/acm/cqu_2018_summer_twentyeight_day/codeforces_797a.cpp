#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>ans(1);
    ans[0]=n;
    for(int i=2;i*i<=ans[0];)
    {
        if(ans.size()==k)break;
        if(ans[0]%i==0)
        {
            ans.push_back(i);
            ans[0]/=i;
        }else ++i;
    }
    if(ans.size()!=k)cout<<-1;
    else
        for(int i:ans)
            cout<<i<<' ';
    return 0;
}