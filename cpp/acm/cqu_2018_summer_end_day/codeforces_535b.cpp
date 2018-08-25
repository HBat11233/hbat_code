#include <bits/stdc++.h>

#define INF 1000000000

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    map<int,int>book;
    queue<int>que;
    book[4]=1;
    book[7]=2;
    int pos=3;
    que.push(4);
    que.push(7);
    while(true)
    {
        int h=que.front();
        que.pop();
        if(h>INF)break;
        h*=10;
        int te=h+4;
        book[te]=pos++;
        que.push(te);
        te=h+7;
        book[te]=pos++;
        que.push(te);
    }
    int n;
    while(cin>>n)
        cout<<book[n]<<endl;
    return 0;
}