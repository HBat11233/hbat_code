#ifndef _VTYPE_H_
#define _VTYPE_H_

#include <bits/stdc++.h>

//template<typename TYPE>

typedef int TYPE;

class Vtype_iterator
{
public:
    Vtype_iterator(){}
    Vtype_iterator(std::vector<TYPE>::iterator it):it(it){}
    TYPE &operator *()
    {
        return *it;
    }
    Vtype_iterator& operator ++()
    {
        ++it;
        return *this;
    }
    Vtype_iterator operator ++(int)
    {
        Vtype_iterator tempit(it);
        it++;
        return tempit;
    }
    bool operator !=(const Vtype_iterator &b)
    {
        return it!=b.it;
    }
    bool operator ==(const Vtype_iterator &b)
    {
        return it==b.it;
    }
    std::vector<TYPE>::iterator getit()
    {
        return it;
    }
private:
    std::vector<TYPE>::iterator it;
};

class Vtype
{
    typedef Vtype_iterator iterator;
public:
    Vtype(int len):arr(len){}
    Vtype(int len,TYPE n):arr(len,n){}
    iterator begin()
    {
        return iterator(arr.begin());
    }
    iterator end()
    {
        return iterator(arr.end());
    }
private:
    std::vector<TYPE>arr;
};

#endif