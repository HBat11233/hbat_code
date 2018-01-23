#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void qsortstr(int b,int r,vector <string> &que)
{
    //if(b==r)return;
    int bl=que[(b+r)/2].size();
    int i=b,j=r;
    while(i<=j)
    {
        while(que[i].size()<bl)i++;
        while(que[j].size()>bl)j--;
        if(i<=j)
        {
            swap(que[i],que[j]);
            i++;
            j--;
        }
    }
    if(i<r)qsortstr(i,r,que);
    if(b<j)qsortstr(b,j,que);
    return;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        vector <string> que(x);
        for(int i=0;i<x;++i)
            cin>>que[i];
        qsortstr(0,que.size()-1,que);
        string str;
        cin>>str;
        system("pause");
    }
    return 0;
}