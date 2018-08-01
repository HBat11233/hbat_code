#include <iostream>
#include <algorithm>
using namespace std;
int maps[400][400];
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=1;i<=n;++i)
            for(int j=1;j<=i;++j)
                cin>>maps[i][j];
        for(int i=n-1;i>=1;--i)
            for(int j=1;j<=i;++j)
                maps[i][j]+=max(maps[i+1][j],maps[i+1][j+1]);
        cout<<maps[1][1]<<"\n";
    }
    return 0;
}