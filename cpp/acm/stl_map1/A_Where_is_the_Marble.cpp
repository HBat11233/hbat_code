#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int,int>ma;
vector <int> que;

int main()
{
    int n,m;
    int tp=0;
    for(cin>>n>>m;n!=0&&m!=0;cin>>n>>m)
    {
        tp++;
        ma.clear();
        que.clear();
        que.resize(n+1);
        int a;
        for(int i=1;i<=n;++i)
            cin>>que[i];
        sort(que.begin()+1,que.end());
        for(int i=1;i<=n;++i)
            if(!ma.count(que[i]))ma[que[i]]=i;
        cout<<"CASE# "<<tp<<":\n";
        for(int i=0;i<m;++i)
        {
            cin>>a;
            if(!ma.count(a))cout<<a<<" not found\n";
            else cout<<a<<" found at "<<ma[a]<<endl;
        }
    }
    return 0;
}