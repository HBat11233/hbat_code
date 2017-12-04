#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class book
{
private:
    string title;//閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓锟�
    string author;//閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓锟�
    string _bo;//"true"涓洪敓鏂ゆ嫹閿熸枻鎷锋檼閿燂拷
public:
    book()//閿熸枻鎷烽敓灞婂嚱閿熸枻鎷烽敓鏂ゆ嫹濮嬮敓鏂ゆ嫹涓洪敓鏂ゆ嫹
        :title{""},author{""},_bo{""}
    {}
    book(string a,string b)//閿熸枻鎷峰閿熸枻鎷�
        :title{a},author{b},_bo{"true"}
    {}
    string Title() {return title;}//閿熶粙鐪媡itle
    string Author() {return author;}//閿熶粙鐪媋uthor
    string Bo() {return _bo;}//閿熶粙鐪嬮敓鏂ゆ嫹鍊奸敓瑙掑嚖鎷锋檼閿燂拷
    void input(string a,string b)//閿熸枻鎷峰€奸敓鏂ゆ嫹閿熸枻鎷�
    {
        title=a;
        author=b;
        _bo="true";//閿熺即鐧告嫹閿熸枻鎷峰€奸敓鏂ゆ嫹閿燂拷
        return;
    }
};

class lib
{
public:
    bool push(book a);//閿熸枻鎷烽敓锟�
    bool out(book a) {return out(a.Title());}//閿熸枻鎷烽敓锟�
    bool out(string a);
    bool in(book a) {return in(a.Title());}//閿熶粙杩�
    bool in(string a);
    bool print();//閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓锟�
private:
    map<string,int>lip;//閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鍙唻鎷烽敓琛楋拷
    vector <book> que;//閿熸枻鎷蜂憨閿熸枻鎷烽敓锟�
    vector <bool> ioo;//閿熸枻鎷烽敓瑙掑嚖鎷烽敓鏂ゆ嫹閿熸枻鎷穞rue涓洪敓鏂ゆ嫹閿熸枻鎷烽敓绲漚lse涓烘病閿熷彨鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹璇熼敓鏂ゆ嫹鏋氶敓鏂ゆ嫹閿熸枻鎷烽敓锟�
    vector <book> sque;//閿熸枻鎷烽敓鐭鎷烽敓鏂ゆ嫹
};

bool lib::push(book a)//閿熸枻鎷烽敓鏂ゆ嫹姒э拷
{
    for(int i=0;i<que.size();++i)
    {
        if(a.Author()<=que[i].Author())//閿熸彮纰夋嫹閿熸枻鎷蜂竴閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓琛楃鎷烽敓鏂ゆ嫹閿熶茎锝忔嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓锟�
        {
            for(;a.Author()==que[i].Author()&&i<que.size();++i)//閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹鍚岄敓鏂ゆ嫹閿熸枻鎷锋媷閿熸枻鎷烽敓锟�
                if(a.Title()<que[i].Title())break;
            que.insert(que.begin()+i,a);//閿熸枻鎷烽敓鏂ゆ嫹
            ioo.insert(ioo.begin()+i,false);
            for(;i<que.size();++i)//閿熺潾闈╂嫹i閿熸枻鎷穒閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽『閿熸枻鎷�
                lip[que[i].Title()]=i;
            return true;
        }
    }
    que.push_back(a);//閿熸枻鎷烽敓鑺傝鎷峰熬閿熸枻鎷烽敓缁炴暆杈炬嫹鍐欓『閿熸枻鎷烽敓锟�
    ioo.push_back(false);
    lip[a.Title()]=que.size()-1;
    return true;
}

bool lib::out(string a)
{
    return ioo[lip[a]]=true; 
}

bool lib::in(string a)//閿熸枻鎷烽敓浠嬭繕閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷锋安鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹鏂滈敓锟�
{
    for(int i=0;i<sque.size();++i)
    {
        if(lip[a]<lip[sque[i].Title()])
        {
            sque.insert(sque.begin()+i,que[lip[a]]);
            ioo[lip[a]]=false;
            return true;
        }
    }
    sque.push_back(que[lip[a]]);//閿熸枻鎷烽敓鏂ゆ嫹閿熻娇璇ф嫹閿熸枻鎷烽敓鏂ゆ嫹鑰勵儽杈炬嫹閿熸枻鎷烽敓鏂ゆ嫹椴侀敓鏂ゆ嫹閿燂拷
    ioo[lip[a]]=false;
    return true;
}

bool lib::print()//閿熸枻鎷烽敓鏂ゆ嫹閿熻甯嫹閿熸枻鎷烽敓鏂ゆ嫹鏂滈敓锟�
{
    for(int i=0;i<sque.size();++i)
    {
        int head=lip[sque[i].Title()]-1;
        for(;head>=0&&ioo[head];--head);
        if(head>=0)cout<<"Put "<<sque[i].Title()<<" after "<<que[head].Title()<<endl;
        else cout<<"Put "<<sque[i].Title()<<" first"<<endl;
    }
    sque.clear();//閿熸枻鎷峰喘閿熸枻鎷烽敓鏂ゆ嫹鏂滈敓锟�
    return true;
}

istream& operator >>(istream& in,book& a)
{
    string str1="",str2="",osr;
    book temp;
    in>>str1;
    if(str1!="END")
    {
        str1+=" ";
        for(in>>osr;osr!="by";in>>osr)
        {
            str1+=osr;
            str1+=" ";
        }
        getline(in,str2);
        for(int i=str1.size()-1;i>=0;--i)
            if(str1[i]==' ')str1.pop_back();
            else break;
        for(int i=str2.size()-1;i>=0;--i)
            if(str2[i]==' ')str2.pop_back();
            else break;
        for(int i=0;i<str1.size();++i)
            if(str1[i]==' ')str1.erase(str1.begin());
            else break;
        for(int i=0;i<str2.size();++i)
            if(str2[i]==' ')str2.erase(str2.begin());
            else break;
        temp.input(str1,str2);
    }
    a=temp;
    return in;
}

ostream& operator <<(ostream& out,book& a)
{
    return out<<"title:"<<a.Title()<<endl<<"author:"<<a.Author()<<endl;
}

int main()
{
    freopen("d.txt","r",stdin);
    freopen("out.txt","w",stdout);
    book a;
    lib st;
    for(cin>>a;a.Bo()=="true";cin>>a)
        st.push(a);
    string str;
    for(cin>>str;str!="END";cin>>str)
    {
        if(str=="BORROW")
        {
            getline(cin,str);
            for(int i=0;i<str.size();++i)
                if(str[i]==' ')str.erase(str.begin());
                else break;
            for(int i=str.size()-1;i>=0;--i)
                if(str[i]==' ')str.pop_back();
                else break;
            st.out(str);
        }
        else if(str=="RETURN")
        {
            getline(cin,str);
            for(int i=0;i<str.size();++i)
                if(str[i]==' ')str.erase(str.begin());
                else break;
            for(int i=str.size()-1;i>=0;--i)
                if(str[i]==' ')str.pop_back();
                else break;
            st.in(str);
        }
        else
        {
            st.print();
            cout<<"END\n";
        }
    }
    system("pause");
    system("pause");
    system("pause");
    system("pause");
    system("pause");
    system("pause");
    system("pause");
    system("pause");
    system("pause");
    system("pause");
    return 0;
}
