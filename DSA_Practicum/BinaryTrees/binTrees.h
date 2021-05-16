#ifndef __BINTREE_H
#define __BINTREE_H

#include <iostream>

template <class T>
class BinTree
{
    private:
    struct Node
    {
        T data;
        Node *left, *right;

        Node(T data) : data(data), left(nullptr), right(nullptr) {};
    };

    Node* locate (const char*) const;
    Node* root;
    void addElementHelper(Node* curr, T element);
    void printSortedHelper(Node* curr);
    int findDepthHelper(Node* curr, T element);

    public:

    BinTree();

    //Вмъква ново листо в дървото на дадена позиция.  
    //Не позволява изменяне на съществуващи елементи
    void add(const T&, const char*);
    T get(const char*) const;
    T& operator [](const char*);
    void toDotty(std::ostream& out);

    bool member (const T& x);
    T min();
    bool isEven();
    bool hasWord(const char * str);

    void addElement(T element);
    void printSorted();
    int findDepth(T element);
    void bfs();
};

#endif