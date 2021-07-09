#include <iostream>

template <class T>
class DoubleLinkedList
{
    struct Node
    {
        T data;
        Node* next;
        Node* prev;
    };

    private:

    Node* first;
    void copy(const DoubleLinkedList<T>& other);
    void clear();

    public:

    DoubleLinkedList();
    DoubleLinkedList(const DoubleLinkedList<T>& other);
    DoubleLinkedList& operator= (const DoubleLinkedList<T>& other);
    ~DoubleLinkedList();
};

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() : first(nullptr) {}

template <typename T>
void DoubleLinkedList<T>::copy(const DoubleLinkedList<T>& other)
{
    if (other.first == nullptr)
    {
        first = nullptr;
        return;
    }
    
    Node* thisNextIter, otherNextIter = other.first;
    first = new Node();
    thisNextIter = first;

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
void DoubleLinkedList<T>::clear()
{

}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList<T>& other)
{
    copy(other);
}

template <typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(const DoubleLinkedList<T>& other)
{
    if (this != &other)
    {
        copy(other);
        clear();
    }
    
    return *this;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    clear();
}