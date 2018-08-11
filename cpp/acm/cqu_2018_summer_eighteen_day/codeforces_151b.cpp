#include <bits/stdc++.h>

using namespace std;

struct ips
{
    int pos;
    string name;
    int t;
    int p;
    int g;
}que[105];

bool compt(const ips& a,const ips& b)
{
    if(a.t==b.t)return a.pos<b.pos;
    return a.t>b.t;
}
bool compp(const ips& a,const ips& b)
{
    if(a.p==b.p)return a.pos<b.pos;
    return a.p>b.p;
}
bool compg(const ips& a,const ips& b)
{
    if(a.g==b.g)return a.pos<b.pos;
    return a.g>b.g;
}

int main()
{
    int n;
    memset(que,0,sizeof(que));
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int m;
        char ch[100];
        cin>>m;
        getchar();
        gets(ch);
        que[i].name=ch;
        //cin>>que[i].name;
        que[i].pos=i;
        string str;
        for(int j=0;j<m;++j)
        {
            cin>>str;
            if(str[0]==str[1]&&str[1]==str[3]&&str[3]==str[4]&&str[4]==str[6]&&str[6]==str[7])
                que[i].t++;
            else if(str[0]>str[1]&&str[1]>str[3]&&str[3]>str[4]&&str[4]>str[6]&&str[6]>str[7])
                que[i].p++;
            else que[i].g++;
        }
    }
    sort(que,que+n,compt);
    printf("If you want to call a taxi, you should call: ");
    for(int i=0;que[i].t==que[0].t&&i<n;++i)
    {
        if(i)cout<<", ";
        cout<<que[i].name;
    }
    cout<<".\n";
    sort(que,que+n,compp);
    printf("If you want to order a pizza, you should call: ");
    for(int i=0;que[i].p==que[0].p&&i<n;++i)
    {
        if(i)cout<<", ";
        cout<<que[i].name;
    }
    cout<<".\n";
    sort(que,que+n,compg);
    printf("If you want to go to a cafe with a wonderful girl, you should call: ");
    for(int i=0;que[i].g==que[0].g&&i<n;++i)
    {
        if(i)cout<<", ";
        cout<<que[i].name;
    }
    cout<<".";
    return 0;
}