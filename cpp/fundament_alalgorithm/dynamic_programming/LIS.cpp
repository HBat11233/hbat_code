#include <iostream>
#include <ctime>
#include <vector>
#include <cmath>

using namespace std;

class lise
{
public:
    lise()
    {lise(10,10);}
    lise(int length)
    {lise(length,10);}
    int size(){return nums.size();}
    lise(int length,int maxs);
    int lis();
    void print();
private:
    vector <int> nums;
};

lise::lise(int length,int maxs)
{
    srand(time(NULL));
    nums.resize(length);
    for(int i=0;i<length;i++)
        nums[i]=rand()%maxs;
}

void lise::print()
{
    for(int i:nums)
        cout<<i<<' ';
    cout<<endl;
    return;
}

int lise::lis()
{
    vector <int> last(nums.size(),-1);
    vector <int> mleng(nums.size(),1);
    vector <int> lleng(nums.size(),1);
    for(int i=1;i<nums.size();++i)
    {
        int m=-1;
        int pos=-1;
        for(int j=0;j<i;++j)
        {
            if(nums[j]<nums[i])
                if(lleng[i]<lleng[j]+1)
                {
                    pos=j;
                    lleng[i]=lleng[j]+1;
                }
        }
//            if(nums[j]<nums[i]&&nums[j]>=m)m=nums[j],pos=j;
        last[i]=pos;
    )
    for(int i=1;i<nums.size();++i)
        if(last[i]==-1||!(last[i]<i))mleng[i]=mleng[i-1];
        else mleng[i]=mleng[i-1]>lleng[last[i]]+1? mleng[i-1]:lleng[last[i]]+1;
    return *mleng.rbegin();
}


int main()
{
    lise a={12,10};
    a.print();
    cout<<a.lis()<<endl;
    system("pause");
    return 0;
}
//40 