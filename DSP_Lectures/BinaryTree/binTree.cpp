#ifndef __BINTREE_CPP
#define __BINTREE_CPP

#include "binTree.h"
#include <cassert>

template <class T>
BinTree<T>::BinTree():root(nullptr) {}

template <class T>
void BinTree<T>::add (const T &x, const char *trace)  
{
    if (root == nullptr)
    {
        assert (trace[0] == 0);
        root = new Node {x,nullptr,nullptr};
        return;
    }

    assert (trace[0] != 0);

    BinTree<T>::Node* current = root;

    while (trace[1] != 0)
    {
        assert(trace[0] == 'L' || trace[0] == 'R');
        
        if (trace[0] == 'L')
        {
            current = current->left;
        } else 
        {
            current = current->right;
        }

        assert (current != nullptr);    
        ++trace;
    }

    if (trace[0] == 'L')
    {
        assert(current->left == nullptr);
        current->left = new Node {x,nullptr,nullptr};
    } else if (trace[0] == 'R')
    {
        assert(current->right == nullptr);
        current->right = new Node {x,nullptr,nullptr};
    } else 
    {
        assert (false);
    }
}

template <class T>
T BinTree<T>::get (const char *trace) const
{

    BinTree<T>::Node* element = locate(trace);
    assert (element != nullptr);
    return element->data;
}

template <class T>
typename BinTree<T>::Node* BinTree<T>::locate (const char *trace) const
{
    BinTree<T>::Node* current = root;
    while (trace[0] != 0)
    {
        assert (current != nullptr);
        assert (trace[0] == 'L' || trace[0] == 'R');

        if (trace[0] == 'L')
        {
            current = current->left;
        } else 
        {
            current = current->right;
        }

        ++trace;
    }

    assert (current != nullptr);
    return current;
}

template <class T>
T& BinTree<T>::operator [](const char *trace)
{
    BinTree<T>::Node* element = locate(trace);
    assert (element != nullptr);
    return element->data; 
}

template <class T>
void BinTree<T>::toDotty(std::ostream& out)
{
    out << "digraph G{\n";
    toDottyHelp(out, root);
    out << "}";
}

template <class T>
int BinTree<T>::max()
{
    return maxHelper(root);
}

template <class T>
int BinTree<T>::maxHelper(Node* node)
{
    if (node == nullptr)
    {
        return INT_FAST32_MIN;
    }
    
    int leftMax = maxHelper(node->left);
    int rightMax = maxHelper(node->right);

    return std::max(node->data, std::max(leftMax, rightMax));
}

template <class T>
bool BinTree<T>::isEven()
{
    return isEvenHelper(root);
}

template <class T>
bool BinTree<T>::isEvenHelper(Node* node)
{
    if (node == nullptr)
    {
        return true;
    }

    return current->data % 2 == 0
           && isEvenHelper(current-left)
           && isEvenHelper(current-right);
}

template <class T>
bool BinTree<T>::hasWord(const char* str)
{
    return hasWordHelper(root, str);
}

template <class T>
bool BinTree<T>::hasWordHelper(Node* node, const char* str)
{
    if (node == nullptr)
    {
        return false;
    }
    
    if (str[0] == node->data)
    {
        isCurrentMatch = matchWord(node, str);
    }

    bool hasLeft = hasWordHelper(node->left, str);
    bool hasRight = hasWordHelper(node->right, str);

    return true;
}

template <class T>
bool BinTree<T>::matchWord(Node* node, const char* str)
{   
    if (node == nullptr)
    {
        return false;
    }

    if(node->left == nullptr && node->right == nullptr && str[1] == '\0')
    {
        return str[0] == node->data;
    }

    if (node->data != str[0])
    {
        return false;
    }
    
    bool leftMatch = matchWord(node->left, ++str);
    bool rightMatch = matchWord(node->right, ++str);

    return leftMatch || rightMatch;
}

int main()
{
    BinTree<int> t;
    t.add(1, "");
    t.add(2, "L");
    t.add(3, "R");
    t.add(4, "LL");
    t.add(5, "LR");

    std::cout << t.max();
}

#endif