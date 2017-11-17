#include <iostream>
#include <map>
#include <string>

using namespace std;

map <string,int> list;
string str1,str2; 

int main()
{
	int n;
	int maxn=-1;
	cin>>n;
	string str1,str2; 
	for(int i=0;i<n;++i)
	{
		cin>>str1>>str2>>str2;
		for(int i=0;i<str1.size();++i)
			if((int)str1[i]<97)str1[i]=(char)((int)str1[i]+32);
		for(int i=0;i<str2.size();++i)
			if((int)str2[i]<97)str2[i]=(char)((int)str2[i]+32);
		list[str1]=list[str2]+1;
		maxn=list[str1]>maxn? list[str1]:maxn;
	} 
	cout<<maxn+1;
	return 0;
} 
