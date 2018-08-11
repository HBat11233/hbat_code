#include <bits/stdc++.h>

using namespace std;

map<char,int>book;

bool pk(string val,int m,int maxx)
{
    int ans=0;
    int bei=1;
    for(int i=val.size()-1;i>=0;--i)
    {
        ans+=book[val[i]]*bei;
        bei*=m;
    }
    return ans<maxx;
}

int main()
{
    for(int i='0';i<='9';++i)
        book[i]=i-'0';
    for(int i='A';i<='Z';++i)
        book[i]=i-'A'+10;
    string strh,strm;
    getline(cin,strh,':');
    getline(cin,strm);
    int pos=0;
    for(;pos<strh.size();++pos)
        if(strh[pos]!='0')break;
    strh=strh.substr(pos,strh.size()-pos);
    pos=0;
    for(;pos<strm.size();++pos)
        if(strm[pos]!='0')break;
    strm=strm.substr(pos,strm.size()-pos);
    int minm=1;
    for(int i=0;i<strh.size();++i)
        minm=max(minm,book[strh[i]]+1);
    for(int i=0;i<strm.size();++i)
        minm=max(minm,book[strm[i]]+1);
    if(!(pk(strh,minm,24)&&pk(strm,minm,60)))cout<<0;
    else if(strh.size()<=1&&strm.size()<=1)cout<<-1;
    else while(pk(strh,minm,24)&&pk(strm,minm++,60))cout<<minm-1<<' ';
    return 0;
}