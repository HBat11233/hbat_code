#include <bits/stdc++.h>

using namespace std;

int Manacher(string str)
{
    string cal;
    for(int i=0;i<str.size();++i)
    {
        cal.push_back('#');
        cal.push_back(str[i]);
    }
    cal.push_back('#');
    int mx,id;
    vector<int>arr(cal.size(),0);
    arr[0]=1;
    arr[1]=2;
    mx=2;
    id=1;
    for(int i=2;i<cal.size();++i)
    {
        arr[i]= mx>i? min(arr[id*2-i],mx-i):1;
        while(i+arr[i]<cal.size()&&i-arr[i]>=0&&cal[i+arr[i]]==cal[i-arr[i]])arr[i]++;
        if(arr[i]+i-1>mx)
        {
            mx=arr[i]+i-1;
            id=i;
        }
    }
    int pos=0;
    for(int i=0;i<cal.size();++i)
        pos= arr[pos]>arr[i]? pos:i;
    return arr[pos]-1;
}

char s[110005];

int main()
{
	//freopen("in.txt","r",stdin);
    string str;
    while(gets(s))
    {
		//str=s;
        cout<<Manacher(s)<<endl;
		if(getchar()!='\n')break;
    }
    return 0;
}