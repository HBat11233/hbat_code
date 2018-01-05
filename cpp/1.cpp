#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class book
{
private:
    string title;//闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呮悂鏌￠崒妯衡偓鏍偓姘秺閺屻劑鎮㈤崨濠勪紕闂佸綊顥撻崗姗€寮幘缁樻櫢闁跨噦鎷�
    string author;//闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呮悂鏌￠崒妯衡偓鏍偓姘秺閺屻劑鎮㈤崨濠勪紕闂佸綊顥撻崗姗€寮幘缁樻櫢闁跨噦鎷�
    string _bo;//"true"婵炴垶鎸诲浠嬪极閹捐妫橀柕鍫濇椤忓爼姊虹捄銊ユ瀾闁哄顭烽獮蹇涙煥鐎ｎ偒鈧盯姊虹捄銊ユ珢闁瑰嚖鎷�
public:
    book()//闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呮悂鎮橀悙璇у伐闁搞倝浜堕弻銊╂偄閸涘﹦浼勯梺褰掝棑閸忔﹢寮幘璇叉闁靛牆妫楅璺衡攽椤旂⒈鍎旈柡浣规崌瀵剟濡堕崱妤婁紦婵炴垶鎸诲浠嬪极閹捐妫橀柕鍫濇椤忥拷
        :title{""},author{""},_bo{""}
    {}
    book(string a,string b)//闂備浇娉曢崰鎰板几婵犳艾绠€瑰嫰鍋婂妤呮⒑鐠恒劌鏋戦柡瀣煼楠炲繘鏁撻敓锟�
        :title{a},author{b},_bo{"true"}
    {}
    string Title() {return title;}//闂備浇娉曢崰宥囧垝濞嗘挻鍎戝┑顖ｆ懆tle
    string Author() {return author;}//闂備浇娉曢崰宥囧垝濞嗘挻鍎戝┑顖氼€乼hor
    string Bo() {return _bo;}//闂備浇娉曢崰宥囧垝濞嗘挻鍎戦悗锝庡枟閺呮悂鏌￠崒妯衡偓鏍偓姘秺瀹曟劖绺介崨濠冩闁荤喐鐟︾敮鎺楀吹閺嶎厼绠梺鍨儐椤庢盯姊虹捄銊ユ珢闁瑰嚖鎷�
    void input(string a,string b)//闂備浇娉曢崰鎰板几婵犳艾绠€瑰嫭澹嬮崑鎾寸附閸涘﹥娅㈤梺鍝勫€堕崐鏍偓姘秺閺屻劑鎮㈤崨濠勪紕闂佺懓鍤栭幏锟�
    {
        title=a;
        author=b;
        _bo="true";//闂備浇娉曢崰鎾诲础閹惰姤鍎岄柛娑橈工椤忓爼姊虹捄銊ユ瀾闁哄顭烽獮蹇撶暋閹靛啿浜惧┑鍌氭啞閺呮悂鏌￠崒妯衡偓鏍偓姘秺閺屻劑鎮ら崒娑橆伓
        return;
    }
};

class lib
{
public:
    bool push(book a);//闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呮悂鏌ㄩ悤鍌涘
    bool out(book a) {return out(a.Title());}//闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呮悂鏌ㄩ悤鍌涘
    bool out(string a);
    bool in(book a) {return in(a.Title());}//闂備浇娉曢崰宥囧垝濞嗘劖浜ら柨鐕傛嫹
    bool in(string a);
    bool print();//闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呮悂鏌￠崒妯衡偓鏍偓姘秺閺屻劑鎮㈤崨濠勪紕闂佸綊顥撻崗姗€寮幘缁樻櫢闁跨噦鎷�
private:
    map<string,int>lip;//闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呮悂鏌￠崒妯衡偓鏍偓姘秺閺屻劑鎮㈤崨濠勪紕闂佸綊顥撻崗姗€寮幘璇叉闁靛牆妫楅鍫曟⒑鐠恒劌鏋戦柡瀣煼楠炲繘鎮滈懞銉︽闂佸憡鐟崑鍛村船婵犳艾绠柣鎴ｅГ閺呮悂鎮跺☉娆樻闁瑰嚖鎷�
    vector <book> que;//闂備浇娉曢崰鎰板几婵犳艾绠柧姘€归崯顐︽⒑鐠恒劌鏋戦柡瀣煼楠炲繘鎮滈懞銉︽闂佽法鍣﹂幏锟�
    vector <bool> ioo;//闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呮悂鎮峰▎鎰瑨闁搞倖鐗犻獮蹇涙倻閼恒儲娅㈤梺鍝勫€堕崐鏍偓姘秺閺屻劑鎮㈤崨濠勪紕闂佸綊顥撻…绫竨e婵炴垶鎸诲浠嬪极閹捐妫橀柕鍫濇椤忓爼姊虹捄銊ユ瀾闁哄顭烽獮蹇涙倻閼恒儲娅㈢紓浣稿级缁辩櫦se婵炴垶鎸鹃崕銈夋儉閸涘瓨鐓ラ柣鏂垮槻瀵ゆ椽鏌￠崒妯衡偓鏍偓姘秺閺屻劑鎮㈤崨濠勪紕闂佸綊顥撻崗姗€寮幘璇叉闁靛牆妫楅鍫曟⒑鐠恒劌鏋戦柡瀣煼楠炲繘鎮滈懞銉︽闂佸搫鍊堕崐鏍偓姘贡閹风娀鎮㈤崗鍏兼闂佸搫鍊堕崐鏍偓姘秺瀵ǹ顫濋懜鍨闂佸搫鍊堕崐鏍偓姘秺閺屻劑鎮㈤崨濠勪紕闂佸綊顥撻崗姗€寮幘缁樻櫢闁跨噦鎷�
    vector <book> sque;//闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呮悂鏌ｉ褍浜い鏃€鍔欓獮蹇涙倻閼恒儲娅㈤梺鍝勫€堕崐鏍偓姘炬嫹
};

bool lib::push(book a)//闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呮悂鏌￠崒妯衡偓鏍偓姘辨嚀椤顧傞柟鍑ゆ嫹
{
    for(int i=0;i<que.size();++i)
    {
        if(a.Author()<=que[i].Author())//闂備浇娉曢崰鎰亹椤旀儳鏋堝璺侯儏椤忓爼姊虹捄銊ユ瀾闁哄顭烽獮蹇涙憥閸屾粠浼囬梻浣芥硶閸犳劙寮告繝姘闁绘垼濮ら弲鎼佹煛閸屾ê鈧牜鈧艾缍婇弻銊╂偄閸涘﹦浼勯梺褰掝棑閸忔﹢寮幘鑸靛仒婵°倕鍠氶弳婊堟煙妞嬪骸鍘撮柡浣规崌瀵剟濡堕崱妤婁紦闂備浇娉曢崰宥夋嚑鎼淬劍鏅查煫鍥ㄦ煥椤忓爼姊虹捄銊ユ瀾闁哄顭烽獮蹇涙倻閼恒儲娅㈤梺鍝勫€堕崐鏍偓姘秺閺屻劑鎮㈤崨濠勪紕闂佸綊顥撻崗姗€寮幘缁樻櫢闁跨噦鎷�
        {
            for(;a.Author()==que[i].Author()&&i<que.size();++i)//闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呮悂鏌￠崒妯衡偓鏍偓姘秺閺屻劑鎮㈤崨濠勪紕闂佸綊顥撻崗姗€寮幘璇叉闁靛牆妫楅鍫曟煕濮橆剛鐒搁柡浣规崌瀵剟濡堕崱妤婁紦闂備浇娉曢崰鎰板几婵犳艾绠梺鍨儏椤庢牠姊虹捄銊ユ瀾闁哄顭烽獮蹇涙倻閼恒儲娅㈤梺璺ㄥ櫐閹凤拷
                if(a.Title()<que[i].Title())break;
            que.insert(que.begin()+i,a);//闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呮悂鏌￠崒妯衡偓鏍偓姘炬嫹
            ioo.insert(ioo.begin()+i,false);
            for(;i<que.size();++i)//闂備浇娉曢崰鎾愁焽妤ｅ啯顥堥柍鍝勫€搁绉堥梻浣芥硶閸犳劙寮告繝姘缂佸本甯￠弻銊╂偄閸涘﹦浼勯梺褰掝棑閸忔﹢寮幘璇叉闁靛牆妫楅鍫曟⒑鐠恒劌鏋戦柡瀣煼楠炲繘鎮滄慨鎰ㄥ亾鎼淬劍鐓ラ柣鏂挎啞閻忣噣鏌熼崙銈嗗
                lip[que[i].Title()]=i;
            return true;
        }
    }
    que.push_back(a);//闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呮悂鏌ら崫鍕偓浠嬵敊閹版澘绠€瑰嫭澹嗛崯鏌ユ⒑鐠恒劌鏋戦柡瀣煼楠炲繘鎮滈懞銉︽缂傚倷鑳堕崑鐐哄汲閸℃ɑ缍囬柣鎰靛墮椤忓爼鏌涢幇顓犳噰闁靛棗閰ｉ弻銊╂偄閸涘﹦浼勯梺褰掝棑閸忔﹢寮幘缁樻櫢闁跨噦鎷�
    ioo.push_back(false);
    lip[a.Title()]=que.size()-1;
    return true;
}

bool lib::out(string a)
{
    return ioo[lip[a]]=true; 
}

bool lib::in(string a)//闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呯ǹ霉閻樺樊鍎撶紒缁樻礋閺屻劑鎮㈤崨濠勪紕闂佸綊顥撻崗姗€寮幘璇叉闁靛牆妫楅鍫曟⒑鐠恒劌鏋戦柡瀣煼楠炲繘鏌ㄧ€ｎ亞鏆旈梺鍝勫€堕崐鏍偓姘秺閺屻劑鎮㈤崨濠勪紕闂佸綊顥撻崗姗€寮幘璇叉闁靛牆妫楅鍫曟煛閸屾稓鐭掗柡浣规崌閺佹捇鏁撻敓锟�
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
    sque.push_back(que[lip[a]]);//闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呮悂鏌￠崒妯衡偓鏍偓姘秺閺屻劑鎮㈢拠娴嬫瀼闁荤姴娉ч崟顐紦闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呮悂鏌￠崒妯衡偓鏍偓姘秺閹虫捇宕熼棃娑樺Ш闁哄鐗忛崑鎾垛偓姘秺閺屻劑鎮㈤崨濠勪紕闂佸綊顥撻崗姗€寮幘璇叉闁靛牆妫楅璺侯渻缂堢姷绐旈柡浣规崌瀵剟濡堕崱妤婁紦闂備浇娉曢崳锕傚箯閿燂拷
    ioo[lip[a]]=false;
    return true;
}

bool lib::print()//闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呮悂鏌￠崒妯衡偓鏍偓姘秺閺屻劑鎮㈠ú缁樺仴闁汇埄鍨奸崰妤冣偓姘秺閺屻劑鎮㈤崨濠勪紕闂佸綊顥撻崗姗€寮幘璇叉闁靛牆妫楅鍫曟煛閸屾稓鐭掗柡浣规崌閺佹捇鏁撻敓锟�
{
    for(int i=0;i<sque.size();++i)
    {
        int head=lip[sque[i].Title()]-1;
        for(;head>=0&&ioo[head];--head);
        if(head>=0)cout<<"Put "<<sque[i].Title()<<" after "<<que[head].Title()<<endl;
        else cout<<"Put "<<sque[i].Title()<<" first"<<endl;
    }
    sque.clear();//闂備浇娉曢崰鎰板几婵犳艾绠€瑰嫭婢橀弸鐘绘⒑鐠恒劌鏋戦柡瀣煼楠炲繘鎮滈懞銉︽闂佸搫鍊堕崐鏍偓姘秺瀵剙饪伴崼鐔告闂佽法鍣﹂幏锟�
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
