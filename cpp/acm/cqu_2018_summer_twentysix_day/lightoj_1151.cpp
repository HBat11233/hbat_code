#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

int book[105];

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int o=1;o<=t;++o)
    {
        memset(book,-1,sizeof(book));
        int n;
        cin>>n;
        for(int i=0;i<n;++i)
        {
            int a,b;
            cin>>a>>b;
            book[a]=b;
        }

    }
    return 0;
}