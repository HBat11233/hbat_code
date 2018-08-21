#include <iostream>
#include <vector>

using namespace std;

void yf(int &a,int &b)
{
    for(int i=2;i<=a&&i<=b;++i)
        if(a%i==0&&b%i==0)return yf(a/=i,b/=i);
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin>>t;
    int o=0;
    while(t--)
    {
        int n;
        int dp=0;
        int temp=0;
        int k=0;
        cin>>n;
        for(int i=0;i<n;++i)
        {
            cin>>temp;
            if(temp>0)
            {
                k++;
                dp+=temp;
            }
            else dp-=temp;
        }
        cout<<"Case "<<++o<<": ";
        if(k!=0)
        {
            yf(dp,k);
            cout<<dp<<'/'<<k<<endl;
        }else cout<<"inf\n";
    }
    return 0;
}