#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    int temp;
    cin>>n;
    vector < vector <int> > a(n);
    vector < vector <int> > ans(n);
    vector < vector <int> > next(n);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=i;++j)
        {
            cin>>temp;
            a[i].push_back(temp);
            ans[i].push_back(temp);
            next[i].push_back(0);
        }
    }
    for(int i=n-2;i>=0;--i)
    {
        for(int j=i;j>=0;--j)
        {
            int temp=max(a[i+1][j],a[i+1][j+1]);
            a[i][j]+=temp;
            if(temp==a[i+1][j])next[i][j]=0;
            else next[i][j]=1;
        }
    }
    cout<<"max="<<a[0][0]<<endl;
    cout<<ans[0][0];
    for(int i=0,j=0;i<n-1;++i,j=j+next[i][j])
    {
        cout<<"->";
        cout<<ans[i+1][j+next[i][j]];
    }
    cout<<endl;
    system("pause");
    return 0;
}