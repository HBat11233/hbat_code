#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    string str="in";
    int num=0;
    int temp=-1;
    int ip=1;
    int i=0;
    int j=0;
    do
    {  
        temp=num;
        stringstream co;
        co<<ip;
        freopen((str+co.str()+".txt").c_str(),"w",stdout);
        for(;i<=10000;++i)
        {
            for(;j<=100000;++j)
            {
                cout<< i<<" "<<j<<endl;
                num++;
                if(num%1000==0)goto A1;
            }
            j=0;
        }
        A1:
        cout<<-1<<' '<<-1<<endl;
        ip++;
    }while(temp!=num);
    return 0;
}