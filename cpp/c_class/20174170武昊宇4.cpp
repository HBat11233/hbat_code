#include <iostream>
#include <vector>
#include <map>

using namespace std;

int sumn(int n)//计算n的各个位数的和
{
    if(n/10==0)return n;
    else return n%10+sumn(n/10);
}

int main()
{
    map <int,int> bok;
    vector <int> list;
    for(int i=1;i<=999999;++i)
    {
        int num=sumn(i);
        if(!bok.count(num))
        {
            bok[num]=1;
            list.push_back(num);
        }
        else
            bok[num]++;
    }
    int maxn=-1;
    int ip;
    for(int i=0;i<list.size();++i)
    {
        if(bok[list[i]]>maxn)
        {
            maxn=bok[list[i]];
            ip=list[i];
        }
    }
    cout<<"max num:"<<ip;
    system("pause");
    return 0;
}

