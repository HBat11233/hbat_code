#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define AX

using namespace  std;

inline char ds(char a)
{
    if(a<='Z'&&a>='A')return a+32;
    else if(a<='z'&&a>='a')return a;
    else return '\0';
}

int main()
{
#ifdef AX
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
#endif
    vector <string> que;
    map<string,bool>kstr;
    kstr["\0"]=true;
    string str;
    char a;
    while(scanf("%c",&a)!=EOF)
    {
        char temp=ds(a);
        if(temp=='\0'&&*str.begin()!='\0')
        {
            if(!kstr.count(str))
            {
                que.push_back(str);
                kstr[str]=true;
            }
            str.clear();
        }     
        else if(temp!='\0')str.push_back(temp);
    }
    sort(que.begin(),que.end());
    for(int i=0;i<que.size();++i)
        cout<<que[i]<<endl;
    return 0;
}
