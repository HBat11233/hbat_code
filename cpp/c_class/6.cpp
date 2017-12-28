#include <iostream>
#include <string>
#include <vector>
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
    freopen("text.txt","w",stdout);
    for(string i:ans)cout<<i<<endl;
    cout<<"Successful!\n";
    system("pause");
    return 0;
}