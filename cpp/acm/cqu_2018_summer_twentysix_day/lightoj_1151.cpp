#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

double dp[104];
int book[105][105];

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
        for(int i=99;i>0;--i)
        {
            for(int j=1;j<6;++j)
            {
                
            }
        }
    }
    return 0;
}