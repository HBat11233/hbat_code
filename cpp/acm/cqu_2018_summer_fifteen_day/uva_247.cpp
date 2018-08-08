#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,o=0;
    while(scanf("%d%d",&n,&m),n+m)
    {
        vector<string>lis;
        map<string,map<string,bool> >w;
        map<string,bool>pk;
        string stra,strb;
        for(int i=0;i<m;++i)
        {
            cin>>stra>>strb;
            w[stra][strb]=true;
            if(!pk[stra])lis.push_back(stra),pk[stra]=true,w[stra][stra]=true;
            if(!pk[strb])lis.push_back(strb),pk[strb]=true,w[strb][strb]=true;
        }
        for(int k=0;k<n;++k)
            for(int i=0;i<n;++i)
                for(int j=0;j<n;++j)
                    w[lis[i]][lis[j]]|=w[lis[i]][lis[k]]&w[lis[k]][lis[j]];
        if(o)printf("\n");
        printf("Calling circles for data set %d:\n",++o);
        pk.clear();
        int num=0;
        while(num!=n)
        {
            
            for(int i=0;i<n;++i)
            {
                if(!pk[lis[i]])
                {
                    int temp=0;
                    for(int j=0;j<n;++j)
                        if(w[lis[i]][lis[j]]&&w[lis[j]][lis[i]])
                        {
                            if(temp)cout<<", ";
                            cout<<lis[j];
                            pk[lis[j]]=true;
                            num++;
                            temp++;
                        }
                    cout<<'\n';
                }
            }
        }
    }
    return 0;
}

/*
5 6
Ben Alexander
Alexander Dolly
Dolly Ben
Dolly Benedict
Benedict Dolly
Alexander Aaron
14 34
John Aaron
Aaron Benedict
Betsy John
Betsy Ringo
Ringo Dolly
Benedict Paul
John Betsy
John Aaron
Benedict George
Dolly Ringo
Paul Martha
George Ben
Alexander George
Betsy Ringo
Alexander Stephen
Martha Stephen
Benedict Alexander
Stephen Paul
Betsy Ringo
Quincy Martha
Ben Patrick
Betsy Ringo
Patrick Stephen
Paul Alexander
Patrick Ben
Stephen Quincy
Ringo Betsy
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Quincy Martha
*/