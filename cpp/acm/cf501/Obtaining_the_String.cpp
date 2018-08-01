#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;



int main()
{
    int n;
    string s,t;
    while(cin>>n>>s>>t)
    {
        int ans[10005];
        int pos=0;
        int arr[60];
        vector<int>que[27];
        int num1[27];
        int num2[27];
        memset(num1,0,sizeof(num1));
        memset(num2,0,sizeof(num2));
        memset(ans,0,sizeof(ans));
        memset(arr,0,sizeof(arr));
        for(int i=0;i<n;++i)
        {
            que[t[i]-'a'].push_back(i);
            num1[s[i]-'a']++;
            num2[t[i]-'a']++;
        }
        bool pk=false;
        for(int i=0;i<26;++i)
            if(num1[i]!=num2[i])
            {
                pk=true;
                break;
            }
        if(pk)cout<<-1<<endl;
        else
        {
            for(int i=n-1;i>=0;--i)
            {
                arr[i]=*que[s[i]-'a'].rbegin();
                que[s[i]-'a'].pop_back();
            }
            for(int i=0;i<n;++i)
            {
                for(int j=1;j<n;++j)
                {
                    if(arr[j-1]>arr[j])
                    {
                        ans[pos++]=j;
                        swap(arr[j-1],arr[j]);
                    }
                }
            }
            printf("%d\n",pos);
            for(int i=0;i<pos;++i)
                printf("%d ",ans[i]);
            printf("\n");
        }
    }
    return 0;
}