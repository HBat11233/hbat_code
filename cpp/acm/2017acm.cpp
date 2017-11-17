#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t;
string str;

int facm()
{
    bool wa=false;
    int ans=0;
    vector <int> a;
    vector <int> c;
    vector <int> m;
    for(int i=0;i<str.size();++i)
    {
        switch(str[i])
        {
            case 'a':
            case 'A':
                a.push_back(i);
                break;
            case 'c':
            case 'C':
                c.push_back(i);
                break;
            case 'm':
            case 'M':
                m.push_back(i);
                break;
        }
    }
    int i=0,j=0,k=0;
    for(;i<a.size();++i)
    {
        wa=false;
        for(;j<c.size();++j)
        {
            if(a[i]<c[j])
            {
                for(;k<m.size();++k)
                {
                    if(c[j]<m[k])
                    {
                        wa=true;
                        ans++;
                        k++;
                        break;
                    }
                }
                if(wa)
                {
                    j++;
                    break;
                }
                else return ans;
            }
        }
        if(j>=c.size())return ans;
    }
    return ans;
}

int main()
{
    cin>>t;
    for(int i=0;i<t;++i)
    {
        cin>>str;
        cout<<facm()<<endl;
    }
//    system("pause");
    return 0;
}