#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int t;
    cin>>t;
    string str;
    while(t--)
    {
        cin>>str;
        int ans=0;
        for(int i=0;i<str.size();++i)
        {
            if(str[i]>='0'&&str[i]<='9')
            {
                ans*=10;
                ans+=str[i]-'0';
            }
        }
        ans*=513;
        cout<<ans<<endl;
    }
    return 0;
}