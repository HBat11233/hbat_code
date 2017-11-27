#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    for(cin>>n;n;cin>>n)
    {
        while(true)
        {
            vector <int> stackout,stackin;
            stackout.resize(n);
            cin>>stackout[0];
            if(!stackout[0])break;
            for(int i=1;i<n;++i)
                cin>>stackout[i];
            for(int i=1,k=0,j=0;i<=n&&j<n;++i,k++)
            {
                stackin.push_back(i);
                while(k>=0&&stackin[k]==stackout[j])
                {
                    stackin.pop_back();
                    k--;
                    j++;
                }
            }
            if(stackin.empty())cout<<"Yes\n";
            else cout<<"No\n";
        }
        cout<<endl;
    }
    return 0;
}