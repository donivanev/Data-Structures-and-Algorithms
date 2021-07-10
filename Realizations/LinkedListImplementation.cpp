#include <iostream>

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
    void copy(const LinkedList<T>& other);
    void clear();

    public:

    LinkedList();
    LinkedList(const LinkedList<T>& other);
    LinkedList& operator= (const LinkedList<T>& other);
    ~LinkedList(); 
};

template <typename T>
LinkedList<T>::LinkedList() : first(nullptr) {}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& other)
{
    if (other.first == nullptr)
    {
        first = nullptr;
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
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
    copy(other);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
    if (this != &other)
    {
        clear(other);
        clear();
    }
    
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}