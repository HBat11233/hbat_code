//数学题？？？？
//codeforces_535b.cpp？？？？
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int A,B,n;
    while(cin>>A>>B>>n)
    {
        int l,k,m;
        cin>>l>>k>>m;
        for(int i=0;i<n;++i)
        {
            int rm=(k-A)/B+1;
            if(rm<l)
            {
                cout<<-1<<endl;
                continue;
            }
            int nm=k*m;
            int rs=(nm-B)/(A+l*B)-1+l;
            cout<<min(rs,rm)<<endl;
        }
    }
    return 0;
}



//((A+(L-1)*B)*(R-L+1)+(R-L)*B)
//(A+L*B)(R-L+!)-B=nm