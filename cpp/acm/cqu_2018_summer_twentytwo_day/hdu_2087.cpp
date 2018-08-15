#include <iostream>
#include <string>

using namespace std;

int ssnext[1005];

int main()
{
    string str;
    while(cin>>str,str!="#")
    {
        string sstr;
        cin>>sstr;
        ssnext[0]=-1;
        for(int i=1,pos=0;i<sstr.size();++i)
        {
            if(sstr[i]==sstr[pos])ssnext[i]=ssnext[pos++];
            else
            {
                ssnext[i]=pos;
                pos=0;
            }
        }
        int ans=0;
        for(int i=0,j=0;i<str.size();)
        {
            if(j==-1||str[i]==sstr[j])
            {
                i++;
                j++;
            }else j=ssnext[j];
            if(j==sstr.size())ans++,j=0;
        }
        cout<<ans<<'\n';
    }
    return 0;
}