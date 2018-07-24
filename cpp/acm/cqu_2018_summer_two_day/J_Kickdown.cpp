#include <bits/stdc++.h>

using namespace std;

int main()
{
    string stra,strb;
    while(cin>>stra>>strb)
    {
        bitset<105>ca,cb;
        int posa,posb;
        if(stra.size()<strb.size())swap(stra,strb);
        posa=stra.size();
        posb=strb.size();
        for(int i=posa-1;i>=0;--i)
        {
            if(stra[i]=='2')ca[i]=1;
        }
        for(int i=posb-1;i>=0;--i)
        {
            if(strb[i]=='2')cb[i]=1;
        }
            
        int dpos=0;
        bitset<105>nb(cb);
        while(!cb.none())
        {
            if((cb^ca)==(ca|cb))break;
            cb<<=1;
            dpos++;
        }
        int ndpos=0;
        dpos=max(posa,dpos+posb);
        if(dpos!=posa)
        {
            while(!nb.none())
            {
                if((nb^ca)==(ca|nb))break;
                nb>>=1;
                ndpos++;
            }
            dpos=min(dpos,ndpos+posa);
        }
        printf("%d\n",dpos);
    }
    return 0;
}