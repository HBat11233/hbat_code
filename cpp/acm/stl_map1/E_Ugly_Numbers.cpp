#include <iostream>
#include <vector>
#include <algorithm>

#define mins(a,b,c) a<(b<c? b:c)? a:(b<c? b:c)

using namespace std;

int a[11]={1,2,3,4,5,6,8,9,10,12,15};
vector <int> cs;
 
inline void ps()
{
    int i=6,j=6,k=3;
    while(cs.size()!=1500)
    {
        int temp=*cs.rbegin();
        while(cs[i]*2<=temp)++i;
        while(cs[j]*3<=temp)++j;
        while(cs[k]*5<=temp)++k;
        cs.push_back(mins(cs[i]*2,cs[j]*3,cs[k]*5));
    }
    return;
}
 
int main()
{
	for(int i=0;i<11;++i)
		cs.push_back(a[i]);
    ps();
    printf("The 1500'th ugly number is %d.\n",*cs.rbegin());
//    system("pause");
    return 0;
}
//859963392
