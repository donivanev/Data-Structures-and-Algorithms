#ifndef _LINKED_LIST_CPP
#define _LINKED_LIST_CPP

#include <stdexcept>

template <class T>
class LinkedList
{
    struct Node
    {
        T data;
        Node* next;
    };

private:
    Node* first;
    Node* last;
    int size;
    void copy(const LinkedList& other);
    void clear();
    Node* find(int index);

public:
    LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList& operator= (const LinkedList& other);
    ~LinkedList();

    void push_back(const T& data);
    void erase_at(int index);
    int getSize();
    T& operator[] (int index);
    void sort();
};

template <typename T>
LinkedList<T>::LinkedList():first(nullptr) {}

template <typename T>
void LinkedList<T>::copy(const LinkedList& other)
{
    /*if (other.first == nullptr)
    {
        first = nullptr;
        last =  nullptr;
        return;
    }

    Node *thisIter, *otherIter = other.first;
    first = new Node();
    thisIter = first;

    while (otherIter != nullptr)
    {
        thisIter->data = otherIter->data;

        if (otherIter->next != nullptr)
        {
            thisIter->next = new Node();
        }

        thisIter = thisIter->next;
        otherIter = otherIter->next;
    }*/

    Node* iter = other.first;
    first = nullptr;
    last = nullptr;

    while (iter != nullptr)
    {
        push_back(iter->data);
    }
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& other):first(nullptr)
{
    copy(other);
}

template <typename T>
LinkedList<T>::LinkedList operator= (const LinkedList& other)
{
    if (this != &other)
    {
        clear();
        copy(other);

        return *this;
    }
}

template <typename T>
void LinkedList<T>::clear()
{
    Node* iter = first;
    Node* temp;

    while (iter != nullptr)
    {   
        temp = iter;
        iter = iter->next;
        delete temp;  
    }

    first = nullptr;
    last = nullptr;
    size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template <typename T>
void LinkedList<T>::push_back(const T& data)
{
    /*auto cell = new Node();
    cell->data = data;
    cell->next = nullptr; // тъй като е последната клетка

    if (first == nullptr)
    {
        first = cell;
        return;
    }

    Node* curr = first;

    while (curr->next != nullptr)
    {
        curr = curr->next;
    }

    curr->next = cell;*/

    auto cell = new Node();
    cell->data = data;
    cell->next = nullptr; // тъй като е последната клетка
    ++size;

    if (first == nullptr)
    {
        first = cell;
        last = first;
        return;
    }

    last->next = cell;
    last = cell;
}

template <typename T>
void LinkedList<T>::erase_at(int index)
{
    Node* curr = first;

    if (index < 0 || index > size - 1)
    {
        return;
    }

    --size;

    if (index == 0)
    {
        first = first->next;
        delete curr;

        if (first == nullptr)
        {
            last = nullptr;
        }
        
        return;
    }

    curr = find(index - 1);
    
    Node* toDelete = curr->next;
    curr->next = curr->next->next;

    if (toDelete == last)
    {
        last = curr;
    }
    
    delete toDelete;
}

template <typename T>
int LinkedList<T>::getSize()
{
    /*Node* curr = first;
    int counter = 0;

    while (curr->next != nullptr)
    {
        curr = curr->next;
        counter++;
    }
    
    return counter;*/

    return size;
}

template <typename T>
T& LinkedList<T>::operator[] (int index)
{
    return find(index)->data;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::find(int index)
{
    if (index < 0 || index >= size)
    {
        throw std::runtime_error("Index out of bounds.");
    }
    
    int currIndex = 0;
    Node* iterator = first;

    while (currIndex != index)
    {
        iterator = iterator->next;
        currIndex++;
    }
    
    return iterator->data;
}

#endif 