#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
/*
string fn(const string &str)
{
    if(str.size()==1)return str;
    int e=str.size()-1;
    if(str[0]==str[e])
    {
        string a=str[0]+fn(str.substr(1,e));
        string b=str[e]+fn(str.substr(0,e));
        return a>b? b:a;
    }
    return str[0]>str[e]? str[e]+fn(str.substr(0,e)):str[0]+fn(str.substr(1,e));
}
*/
int main()
{
    int n;
    scanf("%d",&n);
    int mo=0;
        string str;
        char ch;
        for(int i=0;i<n;++i)
        {
            getchar();
            scanf("%c",&ch);
            str.push_back(ch);
        }
        //cout<<fn(str)<<'\n';
       // printf("\n");
        while(str.size()!=1)
        {
            int e=str.size()-1;
            if(*str.begin()==*str.rbegin())
            {
                string a=str.substr(0,e);
                string c=a;
                reverse(c.begin(),c.end());
                a=min(a,c);
                string b=str.substr(1,e);
                c=b;
                reverse(c.begin(),c.end());
                b=min(b,c);
                if(a>b)goto A1;
                else goto A2;
            }
            else if(*str.begin()<*str.rbegin())
            {A1:
                if(mo==80)
                {
                    mo=0;
                    printf("\n");
                }
                printf("%c",str[0]);
                mo++;
                str=str.substr(1,e);
            }else
            {A2:
                if(mo==80)
                {
                    mo=0;
                    printf("\n");
                }
                printf("%c",*str.rbegin());
                mo++;
                str=str.substr(0,e);
            }
        }
        if(mo==80)
        {
            mo=0;
            printf("\n");
        }
        printf("%c",str[0]);
        mo++;
    return 0;
}