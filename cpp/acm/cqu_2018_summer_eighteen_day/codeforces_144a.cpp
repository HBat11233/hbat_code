#include <bits/stdc++.h>

using namespace std;

int arr[105];

int main()
{
    int n;
    int ans=0;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>arr[i];
    int pos=0;
    for(int i=0;i<n;++i)
        pos= arr[i]>arr[pos]? i:pos;
    ans+=pos;
    for(int i=pos;i>0;--i)
        swap(arr[i],arr[i-1]);
    pos=n-1;
    for(int i=n-1;i>=0;--i)
        pos=arr[i]<arr[pos]? i:pos;
    ans+=n-1-pos;
    cout<<ans;
    return 0;
}