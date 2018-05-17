#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<size_t>ans;
map<int,size_t>know;

int main()
{
    ans.push_back(0);
    ans.push_back(1);
    size_t p=0xF6B75AB2BC471C7ULL*0xAULL+0x1ULL;
    size_t s=0xDE0B6B3A7640000ULL*0xAULL;
    size_t a=10ULL;
    size_t temp;
    do
    {
        size_t len=ans.size();
        temp=0ULL;
        for(int i=0;i<len;++i)
        {
            temp=a+ans[i];
            if(temp<=p)ans.push_back(temp);
        }
        if(a==s)break;
        a*=10;
    }while(true);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
            for(size_t &i:ans)
                if(i!=0&&i%n==0){cout<<i<<endl;break;}
    }
    return 0;
}
