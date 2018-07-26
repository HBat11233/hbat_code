//luan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("1.txt","w",stdout);
    int n;
    vector <string> strs;
    while(scanf("%d",&n),n)
    {
        int mid=(n>>1)-1;
        string ans;
        strs.resize(n);
        for(int i=0;i<n;++i)
            cin>>strs[i];
        sort(strs.begin(),strs.end());
        int i;
        for(i=0;i<strs[mid].size()&&i<strs[mid+1].size();++i)
            if(strs[mid][i]!=strs[mid+1][i])break;
        if(i==strs[mid].size()||i==strs[mid].size()-1)ans=strs[mid];
        else
        {
            ans=strs[mid].substr(0,i+1);
            if(*ans.rbegin()+1==strs[mid+1][i]&&ans.size()==strs[mid+1].size())
                ans.push_back(strs[mid][i+1]);
            if(ans!=strs[mid])
            {
                while(ans<strs[mid])                         //2 ABZXX AC   2 ABZZZ AC
                if(*ans.rbegin()!='Z')ans[ans.size()-1]++;
                else ans.push_back(strs[mid][ans.size()]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}