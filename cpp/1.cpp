#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class book
{
private:
    string title;//�������
    string author;//�������
    string _bo;//"true"Ϊ����ɹ�
public:
    book()//���캯����ʼ��Ϊ��
        :title{""},author{""},_bo{""}
    {}
    book(string a,string b)//��ʼ��
        :title{a},author{b},_bo{"true"}
    {}
    string Title() {return title;}//�鿴title
    string Author() {return author;}//�鿴author
    string Bo() {return _bo;}//�鿴��ֵ�Ƿ�ɹ�
    void input(string a,string b)//��ֵ����
    {
        title=a;
        author=b;
        _bo="true";//�ɹ���ֵ���
        return;
    }
};

class lib
{
public:
    bool push(book a);//���
    bool out(book a) {return out(a.Title());}//���
    bool out(string a);
    bool in(book a) {return in(a.Title());}//�黹
    bool in(string a);
    bool print();//�������
private:
    map<string,int>lip;//�����������б��ַ
    vector <book> que;//��Ķ���
    vector <bool> ioo;//���Ƿ�����trueΪ�����falseΪû�н���������ڸ��ö�����
    vector <book> sque;//���ö���
};

bool lib::push(book a)//����鼮
{
    for(int i=0;i<que.size();++i)
    {
        if(a.Author()<=que[i].Author())//�ҵ���һ�������ֵ����ģ��������
        {
            for(;a.Author()==que[i].Author()&&i<que.size();++i)//��������ͬ����Ĵ���
                if(a.Title()<que[i].Title())break;
            que.insert(que.begin()+i,a);//����
            ioo.insert(ioo.begin()+i,false);
            for(;i<que.size();++i)//�޸�i��i������˳��
                lip[que[i].Title()]=i;
            return true;
        }
    }
    que.push_back(a);//���ڶ�β���ʱִ�д˳���
    ioo.push_back(false);
    lip[a.Title()]=que.size()-1;
    return true;
}

bool lib::out(string a)
{
    return ioo[lip[a]]=true; 
}

bool lib::in(string a)//���黹������뵽�����б�
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
    sque.push_back(que[lip[a]]);//�����β�����룬ִ�����³���
    ioo[lip[a]]=false;
    return true;
}

bool lib::print()//�����ǰ�����б�
{
    for(int i=0;i<sque.size();++i)
    {
        int head=lip[sque[i].Title()]-1;
        for(;head>=0&&ioo[head];--head);
        if(head>=0)cout<<"Put "<<sque[i].Title()<<" after "<<que[head].Title()<<endl;
        else cout<<"Put "<<sque[i].Title()<<" first"<<endl;
    }
    sque.clear();//��ո����б�
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
