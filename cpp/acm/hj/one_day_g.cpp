#include <iostream>

using namespace std;

int c[]={50,25,10,5,1};

int funtion(int n,int p,int snum)
{
    int ans=0;
    if(p==4&&snum+n>100)return 0;
    if(n==0||p==4) return 1;
    for(int i=0;i<=n/c[p];++i)
    {
        if(n-i*c[p]>=0)ans+=funtion(n-i*c[p],p+1,snum+i);
    }
    return ans;
}

int main()
{
    int n;
    while(cin>>n)
    {
        cout<<funtion(n,0,0)<<endl;
    }
    return 0;
}