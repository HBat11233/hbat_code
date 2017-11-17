#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector <int> ip;

int qsort(int l,int r)
{
    int b=ip[(l+r)/2];//�Ƚ�ֵ���� 
    int i=l;
    int j=r;
    while(i<=j)
    {
        while(ip[i]<b)i++;
        while(ip[j]>b)j--;
        if(i<=j)
        {
        	if(i!=j)//��ַ�ظ���Ϊ0 
        	{
            	ip[i]^=ip[j];
            	ip[j]^=ip[i];
            	ip[i]^=ip[j];
            }
            i++;
            j--;
        }
    }
    if(i<r)qsort(i,r);
    if(l<j)qsort(l,j);
    return 0;
}

int main()
{
    int m;
    int n;
    cin>>m;
    for(int i=0;i<m;++i)
    {
        cin>>n;
        ip.resize(n);
        for(int j=0;j<n;++j)
        {
            cin>>ip[j];
        }
        qsort(0,n-1);
        int op=ip[n/2];
        int ans=0;
        for(int j=0;j<n;++j)
        {
            ans+=abs(ip[j]-op);
        }
        cout<<ans<<endl;
    }
    return 0;
}
