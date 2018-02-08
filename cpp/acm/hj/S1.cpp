#include<iostream>
#include <cmath>

using namespace std;

int main()
{
    long long a=2200210122022202212;
    int ans=0;
    int k=0;
    while(a)
    {
        int b=a%10;
        a/=10;
        ans+=b*pow(3,k);
        k++;
    }
    cout<<ans;
}
