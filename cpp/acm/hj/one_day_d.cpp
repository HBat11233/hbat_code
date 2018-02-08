#include <iostream>

using namespace std;
int h[121][121];
bool m[121][121];

int funtion(int num,int mxnum)
{
    int ans=0;
    if(m[num][mxnum])return h[num][mxnum];
    else if(m[num][num]&&mxnum>=num)return h[num][num];
    if(num==0||(mxnum!=0&&num==1))return 1;    
    for(int i=mxnum;i>0;--i)
    {
        for(int j=num/i;j>0;--j)
            ans+=funtion(num-j*i,i-1);
    }
    if(!m[num][mxnum])
    {
        h[num][mxnum]=ans;
        m[num][mxnum]=true;
    }
    else if(!m[num][num]&&mxnum>=num)
    {
        h[num][num]=ans;
        m[num][num]=true;
    }
    return ans;
}

int main()
{
    int n;
    while(cin>>n)
    {
        cout<<funtion(n,n)<<endl;
    }
    return 0;
}