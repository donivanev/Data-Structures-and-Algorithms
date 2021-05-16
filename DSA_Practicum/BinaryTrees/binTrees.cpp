#ifndef __BINTREE_CPP
#define __BINTREE_CPP

#include "binTrees.h"
#include <cassert>
#include <limits> 
#include <queue>

template <class T>
BinTree<T>::BinTree():root(nullptr) {}

template <class T>
void BinTree<T>::add(const T &x, const char *trace)  
{
    if (root == nullptr)
    {
        assert (trace[0] == 0);
        root = new Node {x, nullptr, nullptr};
        return;
    }

    assert (trace[0] != 0);

    BinTree<T>::Node *current = root;

    while (trace[1] != 0)
    {
        assert(trace[0] == 'L' || trace[0] == 'R');
        
        if (trace[0] == 'L')
        {
            current = current->left;
        } 
        else 
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
    } 
    else if (trace[0] == 'R')
    {
        assert(current->right == nullptr);
        current->right = new Node {x,nullptr,nullptr};
    } 
    else 
    {
        assert (false);
    }
}

template <class T>
T BinTree<T>::get(const char *trace) const
{
    BinTree<T>::Node *element = locate(trace);
    assert (element != nullptr);
    return element->data;
}

template <class T>
typename BinTree<T>::Node* BinTree<T>::locate(const char *trace) const
{
    BinTree<T>::Node *current = root;
    while (trace[0] != 0)
    {
        assert (current != nullptr);
        assert (trace[0] == 'L' || trace[0] == 'R');

        if (trace[0] == 'L')
        {
            current = current->left;
        } 
        else 
        {
            current = current->right;
        }

        ++trace;
    }

    assert (current != nullptr);
    return current;
}

template <class T>
T& BinTree<T>::operator[](const char *trace)
{
    BinTree<T>::Node *element = locate(trace);
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

template <typename T>
void BinTree<T>::addElement(T element)
{
    if (root == nullptr)
    {
        Node* first = new Node(element);
        root = first;
        return;
    }
    
    addElementHelper(root, element);
}

template <typename T>
void BinTree<T>::addElementHelper(Node* curr, T element)
{
    if (curr->data > element)
    {
        if (curr->left == nullptr)
        {
            curr->left = new Node(element);
        }
        else 
        {
            addElementHelper(curr->left, element);
        }
    }
    else
    {
        if (curr->right == nullptr)
        {
            curr->right = new Node(element);
        }
        else 
        {
            addElementHelper(curr->right, element);
        }
    }
}

template <typename T>
void BinTree<T>::printSorted()
{
    printSortedHelper(root);
}

template <typename T>
void BinTree<T>::printSortedHelper(Node* curr)
{
    if (curr == nullptr)
    {
        return;
    }
    
    printSortedHelper(curr->left);
    std::cout << curr->data;
    printSortedHelper(curr->right);
}

template <typename T>
int BinTree<T>::findDepth(T element)
{
    findDepthHelper(root, element);
}

template <typename T>
int BinTree<T>::findDepthHelper(Node* curr, T element)
{
    if (curr->data == element)
    {
        return 0;
    }
    if (element <= curr->data)
    {
        return 1 + findDepthHelper(curr->left, element);
    }   
    else
    {
        return 1 + findDepthHelper(curr->right, element);   
    }
}

template <typename T>
void BinTree<T>::bfs()
{
    std::queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* curr = q.front();

        if (curr->left != nullptr)
        {
            q.push(curr->left);
        }

        if (curr->right != nullptr)
        {
            q.push(curr->right);
        }

        std::cout << curr->data << " ";
        q.pop();
    }
}

#endif

int main()
{
    BinTree<int> t;

    t.addElement(5);
    t.addElement(2);
    t.addElement(3);
    t.addElement(1);
    t.addElement(9);

    t.printSorted();
    std::cout << t.findDepth(3);
    t.bfs();

    return 0;
}