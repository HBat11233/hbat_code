#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class book
{
private:
    string title;//锟斤拷锟斤拷锟斤拷锟�
    string author;//锟斤拷锟斤拷锟斤拷锟�
    string _bo;//"true"为锟斤拷锟斤拷晒锟�
public:
    book()//锟斤拷锟届函锟斤拷锟斤拷始锟斤拷为锟斤拷
        :title{""},author{""},_bo{""}
    {}
    book(string a,string b)//锟斤拷始锟斤拷
        :title{a},author{b},_bo{"true"}
    {}
    string Title() {return title;}//锟介看title
    string Author() {return author;}//锟介看author
    string Bo() {return _bo;}//锟介看锟斤拷值锟角凤拷晒锟�
    void input(string a,string b)//锟斤拷值锟斤拷锟斤拷
    {
        title=a;
        author=b;
        _bo="true";//锟缴癸拷锟斤拷值锟斤拷锟�
        return;
    }
};

class lib
{
public:
    bool push(book a);//锟斤拷锟�
    bool out(book a) {return out(a.Title());}//锟斤拷锟�
    bool out(string a);
    bool in(book a) {return in(a.Title());}//锟介还
    bool in(string a);
    bool print();//锟斤拷锟斤拷锟斤拷锟�
private:
    map<string,int>lip;//锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟叫憋拷锟街�
    vector <book> que;//锟斤拷亩锟斤拷锟�
    vector <bool> ioo;//锟斤拷锟角凤拷锟斤拷锟斤拷true为锟斤拷锟斤拷锟絝alse为没锟叫斤拷锟斤拷锟斤拷锟斤拷锟斤拷诟锟斤拷枚锟斤拷锟斤拷锟�
    vector <book> sque;//锟斤拷锟矫讹拷锟斤拷
};

bool lib::push(book a)//锟斤拷锟斤拷榧�
{
    for(int i=0;i<que.size();++i)
    {
        if(a.Author()<=que[i].Author())//锟揭碉拷锟斤拷一锟斤拷锟斤拷锟斤拷锟街碉拷锟斤拷锟侥ｏ拷锟斤拷锟斤拷锟斤拷锟�
        {
            for(;a.Author()==que[i].Author()&&i<que.size();++i)//锟斤拷锟斤拷锟斤拷锟斤拷同锟斤拷锟斤拷拇锟斤拷锟�
                if(a.Title()<que[i].Title())break;
            que.insert(que.begin()+i,a);//锟斤拷锟斤拷
            ioo.insert(ioo.begin()+i,false);
            for(;i<que.size();++i)//锟睫革拷i锟斤拷i锟斤拷锟斤拷锟斤拷顺锟斤拷
                lip[que[i].Title()]=i;
            return true;
        }
    }
    que.push_back(a);//锟斤拷锟节讹拷尾锟斤拷锟绞敝达拷写顺锟斤拷锟�
    ioo.push_back(false);
    lip[a.Title()]=que.size()-1;
    return true;
}

bool lib::out(string a)
{
    return ioo[lip[a]]=true; 
}

bool lib::in(string a)//锟斤拷锟介还锟斤拷锟斤拷锟斤拷氲斤拷锟斤拷锟斤拷斜锟�
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
    sque.push_back(que[lip[a]]);//锟斤拷锟斤拷锟轿诧拷锟斤拷锟斤拷耄达拷锟斤拷锟斤拷鲁锟斤拷锟�
    ioo[lip[a]]=false;
    return true;
}

bool lib::print()//锟斤拷锟斤拷锟角帮拷锟斤拷锟斤拷斜锟�
{
    for(int i=0;i<sque.size();++i)
    {
        int head=lip[sque[i].Title()]-1;
        for(;head>=0&&ioo[head];--head);
        if(head>=0)cout<<"Put "<<sque[i].Title()<<" after "<<que[head].Title()<<endl;
        else cout<<"Put "<<sque[i].Title()<<" first"<<endl;
    }
    sque.clear();//锟斤拷崭锟斤拷锟斤拷斜锟�
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
