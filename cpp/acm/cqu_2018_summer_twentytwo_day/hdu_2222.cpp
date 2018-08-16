//AC自动机
#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

#define INF 1000005

using namespace std;

char str[INF];

struct acnode
{
    int sum;
    acnode *next[26];
    acnode *fail;
    acnode()
    :sum(0),fail(NULL)
    {
        for(int i=0;i<26;++i)
            next[i]=NULL;
    }
}root;

void insrt(char *s)
{
    int len=strlen(s);
    acnode *p=&root;
    for(int i=0;i<len;++i)
    {
        if(p->next[s[i]-'a']==NULL)
        {
            acnode *te = new acnode();
            p->next[s[i]-'a']=te;
        }
        p=p->next[s[i]-'a'];
    }
    p->sum++;
}

void getfail()
{
    acnode * p = &root;
    queue<acnode*>que;
    for(int i=0;i<26;++i)
        if(p->next[i]!=NULL)
        {
            p->next[i]->fail=p;
            que.push(p->next[i]);
        }
    while(!que.empty())
    {
        acnode *h=que.front();
        for(int i=0;i<26;++i)
        {
            if(h->next[i]!=NULL)
            {
                acnode *te = h->fail;
                while(te!=NULL)
                {
                    if(te->next[i]!=NULL)
                    {
                        h->next[i]->fail=te->next[i];
                        break;
                    }else te=te->fail;
                }
                if(te==NULL)h->next[i]->fail=&root;
                que.push(h->next[i]);
            }
        }
        que.pop();
    }
}

int search(char *s)
{
    int ans=0;
    acnode * p = &root;
    for(int i=0;s[i];)
    {
        if(p->next[s[i]-'a']!=NULL)
        {
            acnode * te =p->next[s[i]-'a'];
            while(te!=&root)
            {
                if(te->sum)ans+=te->sum;
                te->sum=0;                           //标记，归零 防止后来重复计数
                te=te->fail;                                                    //在getfail的时候累计起来应该也是可以的
            }
            p=p->next[s[i++]-'a'];
        }
        else
        {
            if(p->fail==NULL)i++;
            else p=p->fail;
        }
    }
    return ans;
}

void acclear(acnode *p)
{
    for(int i=0;i<26;++i)
        if(p->next[i]!=NULL)acclear(p->next[i]);
    if(p!=&root)free(p);
    else root=acnode();
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            scanf("%s",str);
            insrt(str);
        }
        getfail();
        scanf("%s",str);
        printf("%d\n",search(str));
        acclear(&root);
    }
    return 0;
}