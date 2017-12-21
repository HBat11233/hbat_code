#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string temp;
vector <string> num;

inline int str_num(string a)
{
    int ans=0;
    for(int i=0;i<a.size();++i)
    {
        ans*=10;
        ans+=a[i]-' ';
    }
    return ans;
}

int ok[9];
int n,k;
vector <int> lo;
int ans=0x7fffffff;

int dfs(int x)
{
    if(x==k)
    {
        string a;
        int mi=0x7fffffff,ma=-1;
        for(int j=0;j<n;++j)
        {
            a.clear();
            for(int i=0;i<k;++i)
                a+=num[j][lo[i]];
            mi=min(mi,str_num(a));
            ma=max(ma,str_num(a));
        }
        ans=min(ans,abs(mi-ma));
    }
    for(int i=0;i<k;++i)
    {
        if(ok[i])continue;
        ok[i]++;
        lo.push_back(i);
        dfs(x+1);
        lo.pop_back();
        ok[i]--;
    }
    return 0;
}

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;++i)
    {
        cin>>temp;
        num.push_back(temp);
    }
    dfs(0);
    cout<<ans;
    system("pause");
    return 0;
}