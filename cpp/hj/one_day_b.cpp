#include <iostream>

using namespace std;

int main()
{
    int num1,num2,num3;
    while(cin>>num1>>num2>>num3,num1+num2+num3)
    {
        if(!num1)cout<<1<<endl;
        else if(num1+2*num2>=4)cout<<num1+2*num2+5*num3+1<<endl;
        else cout<<num1+2*num2+1<<endl;
    }
    return 0;
}