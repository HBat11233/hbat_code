#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int num;

struct stu
{
    int aw=0;
    int sl=0;
    int be=0;
};

vector <struct stu> cla;
vector <bool> pek(false);

map <int,bool> hax;//haxibiao

inline bool stuaos(int ip)//aw=false,sl=true
{
    int temp=cla[ip].be%(cla[ip].aw+cla[ip].sl);
    if(temp>cla[ip].aw||temp==0) return true;
    else return false;
}

inline int  son()//sleep or not
{
    int ns=0;//awnumber of people
    for(int i=0;i<num;++i)
        if(!pek[i])ns++;
    if(ns==num)return 2;
    else if(ns>num-ns)return 0;
    else return 1;
}

inline bool haxb()
{
    int hx=0;
    for(int i=0;i<num;++i)
    {
        hx*=10;
        hx+=pek[i];
        hx*=10;
        hx+=cla[i].be%(cla[i].aw+cla[i].sl);
    }
    if(hax.count(hx))return false;
    else return hax[hx]=true;
}

int main()
{
    int timz=0;
    int js=0;
    bool wrw=true;
    for(scanf("%d",&num);num!=0;scanf("%d",&num))
    {
        hax.clear();
        cla.clear();
        pek.clear();
        js++;
        cla.resize(num);
        pek.resize(num);
        timz=1;
        int t;
        for(int i=0;i<num;++i)
            cin>>cla[i].aw>>cla[i].sl>>cla[i].be;
        for(int i=0;i<num;++i)//chu shi hua di yi  ci
            pek[i]=stuaos(i),cla[i].be++;
            wrw=haxb();//cun
        do
        {
            vector <bool> temp(num,false);
            vector <bool> temp2(num,false);
            for(int i=0;i<num;++i)
                temp[i]=stuaos(i);
            t=son();
            if(t==2)break;
            for(int i=0;i<num;++i)
            {
                if(!pek[i]&&temp[i])continue;
                temp2[i]=true;
                pek[i]=temp[i];
                cla[i].be++;
            }
            for(int i=0;i<num&&t!=0;++i)
            {
                if(temp2[i])continue;
                pek[i]=true;
                cla[i].be++;
            }
            timz++;
            wrw=haxb();
            t=son();
        }while(t!=2&&wrw);
        if(!wrw&&t!=2) cout<<"Case "<<js<<": "<<-1<<endl;
        else cout<<"Case "<<js<<": "<<timz<<endl;
    }
    return 0;
}