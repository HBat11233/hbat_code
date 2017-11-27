#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int n;
    while(cin>>n,n)
    {
        while(true)
        {
            vector <int> num;
            stack <int> rl;
            num.resize(n);
            cin>>num[0];
            if(num[0]==0)break;
            for(int i=1;i<n;++i)
                cin>>num[i];
            for(int i=1,j=0;i<=n&&j<n;++i)
            {
                rl.push(i);
                while(!rl.empty()&&rl.top()==num[j])
                {
                    rl.pop();
                    j++;
                }
            }
            if(rl.empty())cout<<"Yes\n";
            else cout<<"No\n";
        }
        cout<<endl;
    }
    return 0;
}