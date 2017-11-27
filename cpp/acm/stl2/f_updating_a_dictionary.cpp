#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

inline int fmap()
{
    string oldstr,newstr;
    map <string,string> oldmap,newmap;
    vector <string> oldque,newque;
    cin>>oldstr>>newstr;
    oldstr.erase(0,1);
    oldstr[oldstr.size()-1]=',';
    newstr.erase(0,1);
    newstr[newstr.size()-1]=',';
    while(oldstr.size()>1)
    {
        string tempk,tempv;
        tempk=oldstr.substr(0,oldstr.find(':'));
        oldstr.erase(0,oldstr.find(':')+1);
        tempv=oldstr.substr(0,oldstr.find(','));
        oldstr.erase(0,oldstr.find(',')+1);
        oldque.push_back(tempk);
        oldmap[tempk]=tempv;
    }
    while(newstr.size()>1)//重复
    {
        string tempk,tempv;
        tempk=newstr.substr(0,newstr.find(':'));
        newstr.erase(0,newstr.find(':')+1);
        tempv=newstr.substr(0,newstr.find(','));
        newstr.erase(0,newstr.find(',')+1);
        newque.push_back(tempk);
        newmap[tempk]=tempv;
    }
    sort(oldque.begin(),oldque.end());
    sort(newque.begin(),newque.end());
    bool a=true;
    bool b=true;
    for(int i=0;i<newque.size();i++)
    {
        if(oldmap.count(newque[i]))continue;
        if(a)
        {
            cout<<'+'<<newque[i];
            a=false;
        }
        else cout<<','<<newque[i];
        b=false;
    }
    if(!a)cout<<endl;
    a=true;
    for(int i=0;i<oldque.size();i++)//重复
    {
        if(newmap.count(oldque[i]))continue;
        if(a)
        {
            cout<<'-'<<oldque[i];
            a=false;
        }
        else cout<<','<<oldque[i];
        b=false;
    }
    if(!a)cout<<endl;
    a=true;
    for(int i=0;i<oldque.size();i++)//重复
    {
        if(!newmap.count(oldque[i])||oldmap[oldque[i]]==newmap[oldque[i]])continue;
        if(a)
        {
            cout<<'*'<<oldque[i];
            a=false;
        }
        else cout<<','<<oldque[i];
        b=false;
    }
    if(b){cout<<"No changes";a=false;}
    if(!a)cout<<endl;
    cout<<endl;
    return 0;
}

int main()
{
//    freopen("f.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
        fmap();
//    system("pause");
    return 0;
}