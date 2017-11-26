#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class book
{
private:
    string title;//书的名字
    string author;//书的作者
    string _bo;//"true"为输入成功
public:
    book()//构造函数初始化为空
        :title{""},author{""},_bo{""}
    {}
    book(string a,string b)//初始化
        :title{a},author{b},_bo{"true"}
    {}
    string Title() {return title;}//查看title
    string Author() {return author;}//查看author
    string Bo() {return _bo;}//查看赋值是否成功
    void input(string a,string b)//赋值方法
    {
        title=a;
        author=b;
        _bo="true";//成功赋值标记
        return;
    }
};

class lib
{
public:
    bool push(book a);//添加
    bool out(book a) {return out(a.Title());}//借出
    bool out(string a);
    bool in(book a) {return in(a.Title());}//归还
    bool in(string a);
    bool print();//管理搁置
private:
    map<string,int>lip;//根据书名查列表地址
    vector <book> que;//书的队列
    vector <bool> ioo;//书是否借出，true为借出，false为没有借出，或者在搁置队列中
    vector <book> sque;//搁置队列
};

bool lib::push(book a)//添加书籍
{
    for(int i=0;i<que.size();++i)
    {
        if(a.Author()<=que[i].Author())//找到第一个作者字典序大的，或者相等
        {
            for(;a.Author()==que[i].Author()&&i<que.size();++i)//对作者相同情况的处理
                if(a.Title()<que[i].Title())break;
            que.insert(que.begin()+i,a);//插入
            ioo.insert(ioo.begin()+i,false);
            for(;i<que.size();++i)//修改i和i后的书的顺序
                lip[que[i].Title()]=i;
            return true;
        }
    }
    que.push_back(a);//当在队尾添加时执行此程序
    ioo.push_back(false);
    lip[a.Title()]=que.size()-1;
    return true;
}

bool lib::out(string a)
{
    return ioo[lip[a]]=true; 
}

bool lib::in(string a)//将归还的书插入到搁置列表
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
    sque.push_back(que[lip[a]]);//如果在尾部插入，执行以下程序
    ioo[lip[a]]=false;
    return true;
}

bool lib::print()//输出当前搁置列表
{
    for(int i=0;i<sque.size();++i)
    {
        int head=lip[sque[i].Title()]-1;
        for(;head>=0&&ioo[head];--head);
        if(head>=0)cout<<"Put "<<sque[i].Title()<<" after "<<que[head].Title()<<endl;
        else cout<<"Put "<<sque[i].Title()<<" first"<<endl;
    }
    sque.clear();//清空搁置列表
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
    return 0;
}
