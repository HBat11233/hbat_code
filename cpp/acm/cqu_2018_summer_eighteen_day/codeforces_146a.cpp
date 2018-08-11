#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int arr[60];
    int pos=0;
    int mid=0;
    bool ans=false;
    string str;
    cin>>n>>str;
    for(int i=0;i<n;++i)
    {
        if(i==n/2)mid=pos;
        arr[pos++]=str[i]-'0';
    }
    
    for(int i=0;i<pos;++i)
    {
        if(arr[i]==4||arr[i]==7)continue;
        ans=true;
        break;
    }
    if(ans)printf("NO\n");
    else
    {
        int suma=0;
        int sumb=0;
        for(int i=0;i<mid;++i)
            suma+=arr[i];
        for(int i=mid;i<pos;++i)
            sumb+=arr[i];
        if(suma!=sumb)ans=true;
        if(ans)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}