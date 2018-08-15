//最小表示法
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

string ministr(string str)
{
    int i=0,j=1,k=0;
    int len=str.size();
    while(i<len&&j<len&&k<len)
    {
        int t=str[(i+k)%len]-str[(j+k)%len];
        if(t==0)k++;
        else
        {
            if(t>0) i+=k+1;
            else j+=k+1;
            if(i==j)j++;
            k=0;
        }
    }
    int l=i<j? i:j;
    return str.substr(l,str.size()-l)+str.substr(0,l);
}

int main()
{
    map<string,bool>book;
    int ans=0;
    int n;
    while(~scanf("%d",&n))
    {
        book.clear();
        ans=0;
        string str;
        for(int i=0;i<n;++i)
        {
            cin>>str;
            str=ministr(str);
            if(book[str])continue;
            book[str]=true;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}