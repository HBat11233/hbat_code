#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
        int num1[30];
        int num2[30];
        if(str1.size()!=str2.size())
            cout<<"NO\n";
        else
        {
            memset(num1,0,sizeof(num1));
            memset(num2,0,sizeof(num2));
            for(int i=0;i<str1.size();++i)
            {
                num1[str1[i]-'A']++;
                num2[str2[i]-'A']++;
            }
            sort(num1,num1+30);
            sort(num2,num2+30);
            int i;
            for(i=0;i<30;++i)
            {
                if(num1[i]!=num2[i])
                {
                    cout<<"NO\n";
                    break;
                }
            }
            if(i==30)cout<<"YES\n";
        }
    }
    return 0;
}