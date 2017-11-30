#include <iostream> 
#include <map>
#include <vector>

using namespace std;

struct matrix
{
    int head;
    int tail;
    int ans;
    bool rf;
    matrix()
    {
        head=0;
        tail=0;
        ans=0;
        rf=true;
    }
    matrix& operator *=(const matrix &a)
    {
        if(this->head==0&&this->tail==0){*this=a;return *this;}
        else if(!a.rf||!this->rf||this->tail!=a.head)
        {
        	this->rf=false;
           	return *this;
		}
		else
		{
			ans+=a.ans;
			ans+=head*tail*a.tail;
			tail=a.tail;
			return *this;
		}
    }
    
};
int n;
map <char,matrix> mque;
map <string,matrix> hax;

matrix mul(string str)
{
    if(hax.count(str))return hax[str];
    matrix ans;
    vector <matrix> que;
    if(str.size()==1)ans=mque[str[0]];
    for(int i=1;i<str.size()-1;++i)
    {
        if(str[i]!='(')que.push_back(mque[str[i]]);
        else
        {
            int k,js;
            for(k=i+1,js=1;k<str.size()&&js!=0;++k)
            {
                if(str[k]=='(')js++;
                else if(str[k]==')')js--;
            }
            k-=i;
            que.push_back(mul(str.substr(i,k)));
            i+=k-1;
        }
    }
    for(int i=0;i<que.size();i++)
    {
    	ans*=que[i];
        if(!ans.rf)break;
    }
    hax[str]=ans;
    return ans;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        char temp;
        cin>>temp;
        cin>>mque[temp].head>>mque[temp].tail;
    }
    string str;
    while(cin>>str)
    {
    	matrix ans=mul(str);
    	if(!ans.rf)cout<<"error\n";
    	else cout<<ans.ans<<endl;
    }
    return 0;
}
