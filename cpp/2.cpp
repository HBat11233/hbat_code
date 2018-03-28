#include <stdio.h>
#include <vector>

using namespace std;

struct LS
{
	int a;
	int b;
	int c;
	LS(int a=0,int b=0,int c=0):
		a(a),b(b),c(c){}
};

int n,m;
vector<LS>MMS;
int cl[100001];
int bt[100001];

void inmms(int a,int b,int c)
{
	if(c==0)return;
        int ic=0;
        while(MMS[ic].b<a)ic++;
        if(b==MMS[ic].b)
        {
            if(a==MMS[ic].a)
            {
                MMS[ic].c+=c;
                return;
            }else
            {
                MMS[ic].b=a-1;
                MMS.insert(MMS.begin()+ic+1,LS(a,b,MMS[ic].c+c));
                return;
            }
        }else if(b>MMS[ic].b)
        {
            if(a==MMS[ic].a)
            {
                MMS[ic].c+=c;
                inmms(MMS[ic].b+1,b,c);
                return;
            }else
            {
                int tempb=MMS[ic].b;
                MMS[ic].b=a-1;
                MMS.insert(MMS.begin()+ic+1,LS(a,tempb,MMS[ic].c+c));
                inmms(tempb+1,b,c);
                return;
            }
        }else
        {
            if(a==MMS[ic].a)
            {
                int tempb=MMS[ic].b;
                MMS.insert(MMS.begin()+ic+1,LS(b+1,tempb,MMS[ic].c));
                MMS[ic].b=b;
                MMS[ic].c+=c;
                return;
            }else
            {
                int tempb=MMS[ic].b;
                MMS.insert(MMS.begin()+ic+1,LS(b+1,tempb,MMS[ic].c));
                MMS.insert(MMS.begin()+ic+1,LS(a,b,MMS[ic].c+c));
                MMS[ic].b=a-1;
                return;
            }
        }
	return;
}

int main()
{
	scanf("%d%d\n",&n,&m);
	MMS.push_back(LS(1,n,0));
	for(int i=0;i<m;++i)
	{
		char ch;
		scanf("%c",&ch);
		if(ch=='L')
		{
			int a,b,c;
			scanf("%d%d%d\n",&a,&b,&c);
			inmms(a,b,c);
		}else
		{
			int tenum;
			scanf("%d\n",&tenum);
			for(int j=0;j<MMS.size();++j)
			if(MMS[j].a<=tenum&&MMS[j].b>=tenum)
			{
				printf("%d\n",MMS[j].c+100);
				break;
			}
		}
	}
	return 0;
}
