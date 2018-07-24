#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string str;
        cin>>str;
        string ne=str;
        for(int i=1;i<str.size();++i)
        {
            string te=str.substr(i,str.size()-i)+str.substr(0,i);
            if(ne>te)ne=te;
        }
        cout<<ne<<endl;
    }
    return 0;
}