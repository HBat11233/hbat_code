#include <iostream>
#include <ctime>

using namespace std;

int h[32769][4];

int main()
{
    int n;
    for(int i=0;i<=2;++i)
        for(int j=0;j<32769;++j)
        {
            if(i==1)h[j][i]=1;
            else if(i==0)h[j][i]=0;
            else h[j][i]=j/2+1;
        }
    h[0][0]=1;
    while(cin>>n)
    { 
        int ans=0;
        for(int i=3;i>0;--i)
            for(int j=n/i;j>0;--j)
                ans+=h[n-j*i][i-1];
        h[n][3]=ans;
        cout<<h[n][3]<<endl;

    }
    return 0;
}