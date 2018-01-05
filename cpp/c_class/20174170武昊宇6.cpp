#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    string str;
    cout<<"Input string:";
    cin>>str;
    freopen("a.txt","r",stdin);
    vector <string> ans;
    string temp;
    while(cin>>temp)
    {  
        while(temp.find(str)!=string::npos)
            temp.replace(temp.find(str),str.size(),"");
        ans.push_back(temp);
    }
    fclose(stdin);
    freopen("a.txt","w",stdout);
    for(int i=0;i<ans.size();++i)cout<<ans[i]<<endl;
    fclose(stdout);
    getchar();
    return 0;
}
