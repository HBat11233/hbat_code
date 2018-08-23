#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    long long n,t;
    int o=0;
    while(cin>>n>>t,n!=-1&&t!=-1)
    {
        long long temp=n;
        long long sum=0;
        for(int i=0;i<t;++i)
        {
            while(temp)
            {
                sum+=temp%10;
                temp/=10;
            }
            temp=10;
            while(temp<=sum)
                temp*=10;
            n=n*temp+sum;
            n%=11;
            temp=sum;
        }
        n%=11;
        cout<<"Case #"<<++o<<": "<<(n==0? "Yes\n":"No\n");    
    }
    return 0;
}