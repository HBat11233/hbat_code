#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string om,rm;
    while(cin>>om>>rm)
    {
        bool ko=false;
        map <char,int> o;
        int on[26]={0};
		int rn[26]={0}; 
        for(int i=0;i<26;++i)
            o['A'+i]=0;
        map <char,int> r;
        for(int i=0;i<26;++i)
            r['A'+i]=0;
        for(int i=0;i<om.length();++i)
            o[om[i]]++;
        for(int i=0;i<rm.length();++i)
            r['A'+(int)(rm[i]-'A'+1)%26]++;
        /*
        for(int i=0;i<26;++i)
            if(o['A'+i]!=r['A'+i])
            {
                ko=true;
                break;
            }
        */
        for(int i=0;i<26;++i)
        {
        	on[i]=o['A'+i];
        	rn[i]=r['A'+i];
		}
		sort(on,on+26);
		sort(rn,rn+26);
		for(int i=0;i<26;++i)
		{
			if(on[i]!=rn[i])
			{
				ko=true;
				break;
			}
		}
        if(ko)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
