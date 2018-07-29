#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int n;
    string str;
    while(cin>>n>>str)
    {
        int num=0;
        for(int i=0;i<n;++i)
            if(str[i]=='X')num++;
        if(num==n/2)
            cout<<0<<endl<<str<<endl;
        else
        {
            int ans=0;
            if(num>n/2)
            {
                for(int i=0;i<n&&num!=n/2;++i)
                {
                    if(str[i]=='X')
                    {
                        str[i]='x';
                        num--;
                        ans++;
                    }
                }
            }
            else
            {
                for(int i=0;i<n&&num!=n/2;++i)
                {
                    if(str[i]=='x')
                    {
                        str[i]='X';
                        num++;
                        ans++;
                    }
                }
            }
            cout<<ans<<endl<<str<<endl;
        }
    }
    return 0;
}