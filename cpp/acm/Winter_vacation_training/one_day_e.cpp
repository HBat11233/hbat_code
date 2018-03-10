#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int funtion(int n)
{
    int s=0,temp;
    vector <int> num;
    bool v[10001]={0};
    vector <int> ans;
    for(int i=0;i<n;++i)
    {
        cin>>temp;
            v[temp]=true;
            int k=num.size();
            for(int j=0;j<k;++j)
            {
                if(!v[num[j]+temp])
                {
                    v[num[j]+temp]=true;
                    num.push_back(num[j]+temp);
                }
                if(!v[abs(num[j]-temp)])
                {
                    v[abs(num[j]-temp)]=true;
                    num.push_back(abs(num[j]-temp));
                }
            }
            num.push_back(temp);
        s+=temp;
        //v[s]=true;
    }
    int ansnum=0;
    for(int i=1;i<=s;++i)
    {
        if(!v[i])
        {
            ansnum++;
            ans.push_back(i);
        }
    }
    cout<<ansnum<<endl;
    if(ansnum==0)return ansnum;
    for(int i=0;i<ansnum-1;++i)
        cout<<ans[i]<<' ';
    cout<<ans[ansnum-1]<<endl;
    return ansnum;
}

int main()
{
    int n;
    while(cin>>n)
    {
        funtion(n);
    }
    return 0;
}