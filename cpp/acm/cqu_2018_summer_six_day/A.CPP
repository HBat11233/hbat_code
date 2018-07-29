#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int n,a,b;
    while(cin>>n>>a>>b)
    {
        int num;
        map<int,int>book;
        for(int i=0;i<a;++i)
        {
            cin>>num;
            book[num]=1;
        }
        for(int i=0;i<b;++i)
        {
            cin>>num;
            book[num]=2;
        }
        for(int i=1;i<=n;++i)
        {
            if(book.count(i))
            cout<<book[i]<<' ';
            else cout<<1<<' ';
        }
        cout<<endl;
    }
    return 0;
}