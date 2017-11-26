#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int runf()
{
    int n;
    map <int,vector<int>> a;
    vector <int> que;
    int x,y;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>x>>y;
        que.push_back(y);
        a[y].push_back(x);
    }
    sort(que.begin(),que.end());
    for(int i=1;i<que.size();)
    {
        if(que[i]==que[i-1])que.erase(que.begin()+i);
        else ++i;
    }
    for(int i=0;i<que.size();++i)
        sort(a[que[i]].begin(),a[que[i]].end());
    int i=0;
    int l=0;
    int r=a[que[i]].size()-1;
    int temp=a[que[i]][l]+a[que[i]][r];
    for(i=0;i<que.size();++i)
    {
        l=0;
        r=a[que[i]].size()-1;
        for(;l<=r;++l,--r)
            if(temp!=a[que[i]][l]+a[que[i]][r])break;
        if(l<=r)break;
    }
    if(i<que.size())cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        runf();
    return 0;
}