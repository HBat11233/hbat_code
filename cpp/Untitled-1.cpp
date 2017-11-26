#include "algorithm"
#include "iostream"
#include "string"
#include "vector"
#include "map"

using namespace std;

struct book
{
	string name,author;
	int vis;
};

map<string,int>pb;
map<int,string>pn;
vector<book>pv;
vector<string>q;

int cmp(book bk1,book bk2)
{
	if(bk1.author == bk2.author)return bk1.name < bk2.name;
	else return bk1.author < bk2.author;
}

int cmp_name(string a,string b)
{
	return pb[a]<pb[b];
}

int main()
{
	freopen("d.txt","r",stdin);
	string temp;
	while(getline(cin,temp) && temp !="END")
	{
		book d;
		d.name=temp.substr(0,temp.find_last_of("\"")+1);
		d.author=temp.substr(temp.find_last_of("by")+2,temp.length()-temp.find_last_of("by"-3));
		d.vis=1;
		pv.push_back(d);
	}
	
	sort(pv.begin(),pv.end(),cmp);
	for(int i=0,t=pv.size();i<t;i++)
	{
		pb[pv[i].name]=i;
		pn[i]=pv[i].name;
		//cout << pv[i].name <<endl<< pv[i].author<<endl<<pv[i].vis<<endl;
	}
	
	while(getline(cin,temp) && temp!="END")
	{
		if(temp[0]=='B')
		{
			
			string name=temp.substr(temp.find_first_of("\""),temp.length()-temp.find_first_of("\""));
			pv[pb[name]].vis=0;
			//cout << name <<endl;
		}
		
		if(temp[0]=='R')
		{
			string name=temp.substr(temp.find_first_of("\""),temp.length()-temp.find_first_of("\""));
			q.push_back(name);
		}
		
		if(temp[0]=='S')
		{
			
			sort(q.begin(),q.end(),cmp_name);
			//for(int i=0;i<q.size();i++)cout<<q[i]<<endl; 
			
			for(int i=0,t=q.size();i<t;i++)//遍历q中每一个.
			{
				for(int j=pb[q[i]];j>=0;j--)
				{
					if(pv[pb[pn[j]]].vis==1)
					{
						//Put "The C Programming Language" after "The Canterbury Tales"
						cout<<"Put "<<q[i]<<" after "<<pv[pb[pn[j]]].name<<endl;
						pv[pb[q[i]]].vis=1;
						break;
					}
					
					if(j==0 && pv[pb[pn[j]]].vis==0)
						cout <<"Put "<<q[i]<<" first"<<endl;
				}
				
			}
			cout <<"END"<<endl;
			q.clear();
			
		}
		
	}
	return 0;
}