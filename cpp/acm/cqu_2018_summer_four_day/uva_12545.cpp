#include <bits/stdc++.h>
//#define DEBUG
using namespace std;

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int t;
    scanf("%d",&t);
    for(int o=1;o<=t;++o)
    {
        string str1,str2;
        cin>>str1>>str2;
        vector<int>error_pos0;
        vector<int>error_pos1;
        vector<int>error_w;
        int ans=0;
        for(int i=0;i<str1.size();++i)
        {
            if(str1[i]!=str2[i])
            {
                if(str2[i]=='0')
                {
                    if(str1[i]=='?')ans++;
                    else error_pos0.push_back(i);
                }
                else if(str2[i]=='1')
                {
                    if(str1[i]=='?')error_w.push_back(i);
                    else error_pos1.push_back(i);
                }
            }
        }
        if(error_pos0.size()>error_pos1.size()+error_w.size())ans=-1;
        else
        {
            if(error_pos0.size()<=error_pos1.size())
                ans+=error_pos1.size()+error_w.size();
            else ans+=error_pos0.size()+error_w.size();
        }
        printf("Case %d: %d\n",o,ans);
    }
    return 0;
}


