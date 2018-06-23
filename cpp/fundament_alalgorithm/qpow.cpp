#include <bits/stdc++.h>

using namespace std;

int qpow(int a,int n)
{
    int ans=1;
    int temp=a;
    int p=n;
    while(p)
    {
        if(p&1)ans*=temp;
        temp*=temp;
        p>>=1;
    }
    return ans;
}

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        cout<<qpow(a,b)<<endl;
    }
    return 0;
}