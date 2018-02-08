#include <iostream>
#define P(a) (a*a)

using namespace std;

int funnum(int num,int n)
{
    int ans=0;
    for(int i=n;i>0;--i)
    {
        int temp=num/P(i);
        if(!temp)continue;
        else
        {
                if(num-P(i)<4||i==1)
                    ans++;
                else ans+=funnum(num-P(i),i);
        }
    }
    return ans;
}

int main()
{
    int num;
    while(cin>>num,num)
    {
        cout<<funnum(num,17)<<endl;
    }
    return 0;
}