#include <bits/stdc++.h>

#define INF 100005

using namespace std;

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int n;
    string str;
    cin>>n>>str;
    int ans=0;
    for(int i=n;i<str.size();i+=n)
        if(str[i-1]==str[i-2]&&str[i-2]==str[i-3])ans++;
    cout<<ans<<'\n';
    return 0;
}