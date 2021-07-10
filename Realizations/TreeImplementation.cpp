#include <iostream>

template <class T>
class Tree
{
    struct Node
    {
        T data;
        Node* left, *right;
    };

    private:

    Node* root;
    void copy(const Tree<T>& other);
    void clear();

    public:

    Tree();
    Tree(const Tree<T>& other);
    Tree& operator= (const Tree<T>& other);
    ~Tree();
};

template <typename T>
Tree<T>::Tree() : root(nullptr) {}

template <typename T>
void Tree<T>::copy(const Tree<T>& other)
{

}

template <typename T>
void Tree<T>::clear()
{
    if (root == nullptr)
    {
        return;
    }
    
    
    
}

template <typename T>
Tree<T>::Tree(const Tree<T>& other)
{
    copy(other);
}

template <typename T>
Tree<T>& Tree<T>::operator=(const Tree<T>& other)
{
    if (this != &other)
    {
        copy(other);
        clear();
    }
    
    return *this;
}

template <typename T>
Tree<T>::~Tree()
{
    clear();
}