#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class book
{
private:
    string title;//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻敓锟�
    string author;//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻敓锟�
    string _bo;//"true"娑撴椽鏁撻弬銈嗗闁跨喐鏋婚幏閿嬫闁跨噦鎷�
public:
    book()//闁跨喐鏋婚幏鐑芥晸鐏炲﹤鍤遍柨鐔告灮閹风兘鏁撻弬銈嗗婵鏁撻弬銈嗗娑撴椽鏁撻弬銈嗗
        :title{""},author{""},_bo{""}
    {}
    book(string a,string b)//闁跨喐鏋婚幏宄邦潗闁跨喐鏋婚幏锟�
        :title{a},author{b},_bo{"true"}
    {}
    string Title() {return title;}//闁跨喍绮欓惇濯tle
    string Author() {return author;}//闁跨喍绮欓惇濯媢thor
    string Bo() {return _bo;}//闁跨喍绮欓惇瀣晸閺傘倖瀚归崐濂告晸鐟欐帒鍤栭幏閿嬫闁跨噦鎷�
    void input(string a,string b)//闁跨喐鏋婚幏宄扳偓濂告晸閺傘倖瀚归柨鐔告灮閹凤拷
    {
        title=a;
        author=b;
        _bo="true";//闁跨喓鍗抽惂鍛婂闁跨喐鏋婚幏宄扳偓濂告晸閺傘倖瀚归柨鐕傛嫹
        return;
    }
};

class lib
{
public:
    bool push(book a);//闁跨喐鏋婚幏鐑芥晸閿燂拷
    bool out(book a) {return out(a.Title());}//闁跨喐鏋婚幏鐑芥晸閿燂拷
    bool out(string a);
    bool in(book a) {return in(a.Title());}//闁跨喍绮欐潻锟�
    bool in(string a);
    bool print();//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻敓锟�
private:
    map<string,int>lip;//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閸欘偅鍞婚幏鐑芥晸鐞涙鎷�
    vector <book> que;//闁跨喐鏋婚幏铚傛啫闁跨喐鏋婚幏鐑芥晸閿燂拷
    vector <bool> ioo;//闁跨喐鏋婚幏鐑芥晸鐟欐帒鍤栭幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风rue娑撴椽鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸缁叉細lse娑撶儤鐥呴柨鐔峰建閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚圭拠鐔兼晸閺傘倖瀚归弸姘舵晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻敓锟�
    vector <book> sque;//闁跨喐鏋婚幏鐑芥晸閻偉顔愰幏鐑芥晸閺傘倖瀚�
};

bool lib::push(book a)//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚瑰褝鎷�
{
    for(int i=0;i<que.size();++i)
    {
        if(a.Author()<=que[i].Author())//闁跨喐褰喊澶嬪闁跨喐鏋婚幏铚傜闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撶悰妤冾暜閹风兘鏁撻弬銈嗗闁跨喍鑼庨敐蹇斿闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻敓锟�
        {
            for(;a.Author()==que[i].Author()&&i<que.size();++i)//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗閸氬矂鏁撻弬銈嗗闁跨喐鏋婚幏閿嬪闁跨喐鏋婚幏鐑芥晸閿燂拷
                if(a.Title()<que[i].Title())break;
            que.insert(que.begin()+i,a);//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚�
            ioo.insert(ioo.begin()+i,false);
            for(;i<que.size();++i)//闁跨喓娼鹃棃鈺傚i闁跨喐鏋婚幏绌掗柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑姐€庨柨鐔告灮閹凤拷
                lip[que[i].Title()]=i;
            return true;
        }
    }
    que.push_back(a);//闁跨喐鏋婚幏鐑芥晸閼哄倽顔愰幏宄扮啲闁跨喐鏋婚幏鐑芥晸缂佺偞鏆嗘潏鐐閸愭瑩銆庨柨鐔告灮閹风兘鏁撻敓锟�
    ioo.push_back(false);
    lip[a.Title()]=que.size()-1;
    return true;
}

bool lib::out(string a)
{
    return ioo[lip[a]]=true; 
}

bool lib::in(string a)//闁跨喐鏋婚幏鐑芥晸娴犲绻曢柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏閿嬪畨閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗閺傛粓鏁撻敓锟�
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
    sque.push_back(que[lip[a]]);//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔诲▏鐠囇勫闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归懓鍕靛劷鏉堢偓瀚归柨鐔告灮閹风兘鏁撻弬銈嗗妞翠線鏁撻弬銈嗗闁跨噦鎷�
    ioo[lip[a]]=false;
    return true;
}

bool lib::print()//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔活潡鐢喗瀚归柨鐔告灮閹风兘鏁撻弬銈嗗閺傛粓鏁撻敓锟�
{
    for(int i=0;i<sque.size();++i)
    {
        int head=lip[sque[i].Title()]-1;
        for(;head>=0&&ioo[head];--head);
        if(head>=0)cout<<"Put "<<sque[i].Title()<<" after "<<que[head].Title()<<endl;
        else cout<<"Put "<<sque[i].Title()<<" first"<<endl;
    }
    sque.clear();//闁跨喐鏋婚幏宄板枠闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归弬婊堟晸閿燂拷
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
