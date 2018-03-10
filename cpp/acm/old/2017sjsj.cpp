#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string num;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>num;
        cout<<'6';
        for(int i=6;i<11;++i)
            cout<<num[i];
        cout<<endl;
    }
//    system("pause");
return 0;
}