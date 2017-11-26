#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    map <string,int>dic;
    vector <string> que;
    string str;
    while(cin>>str)
    {
        que.push_back(str);
        dic[str]=1;
    }
    for(int k=0;k<que.size();++k)
    {
        for(int i=1;i<que[k].size()-1;++i)
        {
            string a=que[k].substr(0,i);
            string b=que[k].substr(i,que[k].size()-i);
            if(dic.count(a)&&dic.count(b))
            {
                cout<<que[k]<<endl;
                break;
            }
        }
    }
    return 0;
}