#ifndef __BINTREE_H
#define __BINTREE_H

#include <iostream>

template <class T>
class BinTree
{
    public:

    BinTree();

    //Вмъква ново листо в дървото на дадена позиция. Не позволява 
    //изменяне на съшествуващи елементи
    void add (const T&, const char*);
    T get (const char*) const;
    T& operator [](const char*);
    void toDotty(std::ostream& out);
    int max();
    int isEven();
    bool hasWord(const char* str);

    bool member (const T& x);

    private:
    struct Node
    {
        T data;
        Node *left, *right;
    };

    Node* locate (const char*) const;
    Node* root;

    int maxHelper(Node* node);
    int isEvenHelper(Node* node);
    bool hasWordHelper(Node* node, const char* str)
};

#endif