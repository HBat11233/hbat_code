#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int vecsum(vector<int>&a)
{
    int sum=0;
    for(int i:a)
        sum+=i;
    return sum;
}

int main()
{
    int n;
    while(cin>>n,n>0)
    {
        int sum=0;
        int sum1;
        vector<int>que;
        int a,b;
        for(int i=0;i<n;++i)
        {
            cin>>a>>b;
            sum+=a*b;
            while(b--)
                que.push_back(a);
        }
        sort(que.begin(),que.end());
        vector<int>s(que.size(),0);
        int agv=(float)sum/2.0+0.5;
        sum1=vecsum(que);
        int last=sum1;
        while(sum1>=agv)
        {
            int d=0x7fffffff,di=0,dj=-1;
            last=sum1;
            for(int i=0;i<que.size();++i)
            {
                if(que[i]==0)continue;
                if(que[i-1]==0)di=i;
                for(int j=que.size()-1;j>=0;--j)
                {
                     if(que[i]-s[j]>0&&que[i]-s[j]<d)
                     {
                         d=que[i]-s[j];
                         di=i;
                         dj=j;
                     }
                }
            }
            if(dj==-1)
            {
                sum1+=(s[0]-que[di]);
                //sum2+=que[di]-s[0];
                swap(que[di],s[0]);
            }else
            {
                sum1+=(s[dj]-que[di]);
                //sum2+=que[di]-s[dj];
                swap(que[di],s[dj]);
            }
        }
        if(abs(sum-2*sum1)>abs(sum-2*last))
            cout<<max(last,sum-last)<<' '<<min(last,sum-last)<<endl;
        else cout<<max(sum1,sum-sum1)<<' '<<min(sum1,sum-sum1)<<endl;
        /*
        for(a=1;a<que.size();++a)
        {
            s[a]=s[a-1]+que[a];
            if(s[a]>=agv)break;
        }
        if(abs(sum-2*s[a])>abs(sum-2*s[a-1]))
            cout<<max(s[a-1],sum-s[a-1])<<' '<<min(s[a-1],sum-s[a-1])<<endl;
        else cout<<max(s[a],sum-s[a])<<' '<<min(s[a],sum-s[a])<<endl;
        */
    }
    return 0;
}