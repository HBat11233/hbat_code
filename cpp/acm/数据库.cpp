#include <iostream>
#include <map>
#include <string>

using namespace std;

const int MAXN=10001;
const int MAXM=101;

int n,m;
map <string,int> str;
map <int,int>mak;
int st[MAXN][MAXM];

int main()
{
	bool ijk=0;
    cin>>n>>m;
    for(int i=1,j,s=0;i<=n;++i)
    {
        static string a;
        
        for(j=1;j<m;++j)
        {
            getline(cin,a,',');
//            cout<<a<<str.count(a)<<endl; 
            if(str.count(a))st[i][j]=str[a];
            else 
            {
                str[a]=s;
                st[i][j]=s;
                s++;
            }
        }
        cin>>a;
 //       cout<<a<<str.count(a)<<endl; 
        if(str.count(a))st[i][j]=str[a];
        else 
        {
            str[a]=s;
            st[i][j]=s;
            s++;
        }
    }
    for(int j=1;j<=m;++j)
	{
		for(int i=1;i<=n;++i)
		{
			if(mak.count(st[i][j]))
			{
				for(int k=j+1;k<=m;++k)
				{
					int f=mak[st[i][j]];//和前几行对应 
					if( st[i][k]==st[f][k] )
					{
						cout << mak[ st[i][j] ] << ' ' << i << endl;
						cout << j << ' ' << k << endl;
						ijk=1;
					}
				}
			}else
			{
				mak[st[i][j]]=i;
			}
		}
	}
	if(ijk)cout<<"yes";//与标准题意不同 
	else cout<<"no"; 
    return 0;
}
