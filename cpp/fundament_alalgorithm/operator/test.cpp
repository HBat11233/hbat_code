#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAXN 4000

using namespace std;

struct BIGNUM
{
    int len,s[MAXN];//member

    BIGNUM()//constructed function
    {
        len=1;
        memset(s,0,sizeof(s));
    }

    BIGNUM operator = (const char* num)//Reload operator
    {
        len = strlen(num);
        for(int i=0;i<len;++i)
        {
            s[i]=num[len-i-1]-'0';
        }
        return *this;
    }

    BIGNUM operator = (const int num)
    {
        char a[MAXN];
        sprintf(a,"%d",num);
        *this=a;//Reload char num[] =
        return *this;
    }

    BIGNUM(int num){*this=num;}//Reload constructed function
    BIGNUM(char num[]){*this=num;}
};
//reload << >> 
ostream& operator << (ostream &out,const BIGNUM& x)
{
    for(int i=x.len-1;i>=0;--i)
        cout<<x.s[i];
    return out;
}

istream& operator >> (istream &in,BIGNUM& x)
{
    char num[MAXN];
    in>>num;
    x=num;
    return in;
}


int main()
{
    BIGNUM a;
    cin>>a;
    cout<<a;
    system("pause");
    return 0;
}