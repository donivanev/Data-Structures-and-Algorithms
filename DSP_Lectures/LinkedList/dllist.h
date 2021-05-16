#ifndef __DLLIST_H
#define __DLLIST_H

#include <iostream>
#include "dllist.cpp"

template <class T>
class DLList
{
    public:
    DLList();
    DLList(const DLList<T>&);
    ~DLList();
    DLList<T>& operator= (const DLList<T>&);
    //& - самия обект, а не копие (по псевдоним), с копие се зацикля

    DLList<T> operator+ (const T&) const;
    DLList<T>& operator+= (const T &x);

    private:
        struct box
        {
            T data;
            box *next, *prev;
        };

        box *first;

        template <class E>
        friend std::ostream& operator<< (std::ostream&, const DLList<E>&);

        void copy(const DLList<T> &other);
        void clear();
};

template <class T>
std::ostream& operator<< (std::ostream&, const DLList<T>&);

#endif