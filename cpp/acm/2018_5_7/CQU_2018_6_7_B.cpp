#include <bits/stdc++.h>

using namespace std;

set<string> ans;

string str(16,'0');
char bs[4];
bool pk[10];

inline void dfsm(int n)
{
    int k=n;
    if(n>6)n+=2;
    else if(n>3)n+=1;
    str[n-1]=
    str[n]=
    str[n+3]=
    str[n+4]=k+'0';
    return;
}
inline void bf(int n)
{
    if(n>6)n+=2;
    else if(n>3)n+=1;
    bs[0]=str[n-1];
    bs[1]=str[n];
    bs[2]=str[n+3];
    bs[3]=str[n+4];
    return;
}
inline void hy(int n)
{
    if(n>6)n+=2;
    else if(n>3)n+=1;
    str[n-1]=bs[0];
    str[n]=bs[1];
    str[n+3]=bs[2];
    str[n+4]=bs[3];
    return;
}

void dfs(int n)//暴力全排列
{
    if(n==9)
    {
        //cout<<str<<endl;
        ans.insert(str);
        return;
    }
    for(int i=1;i<=9;++i)
    {
        if(pk[i])continue;
        pk[i]=true;
        bf(i);
        dfsm(i);
        //cout<<str<<endl;
        dfs(n+1);

        pk[i]=false;
        hy(i);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    dfs(0);
    while(t--)
    {
        string istr(16,'0');
        int ch;
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j)
            {
                scanf("%d",&ch);
                istr[i*4+j]=ch+'0';
            }
        if(ans.count(istr))cout<<"Lucky dog!\n";
        else cout<<"BOOM!\n";
    }
    return 0;
}
