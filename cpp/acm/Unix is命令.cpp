#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string str[105];

int main()
{
	int n;
	int maxn=0;
	int k;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>str[i];
		maxn=maxn>str[i].length()? maxn:str[i].length();
	}
	sort(str,str+n);
	k=(60-maxn)/(maxn+2)+1;
	if(n%k!=0)k=n/k+1;
	else k=n/k;
	for(int i=0;i<k;++i)
		str[i].resize(maxn);
	for(int i=k;i<n;++i)
		str[i].resize(maxn+2);
	for(int i=0;i<k;++i)
	{
		for(int j=1;i+j*k<=60;++j)
			str[i]+=str[i+j*k];
	}
	for(int i=0;i<k;++i)
		cout<<str[i]<<endl;
	return 0;
} 
