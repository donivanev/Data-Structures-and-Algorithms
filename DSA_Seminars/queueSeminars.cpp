#ifndef _QUEUE_SEMINARS_H_
#define _QUEUE_SEMINARS_H_
#include <iostream>
#include <cassert>

template <typename T>
class QueueSeminars
{
    private:
    class Node
    {
        T data;
        Node* next;
    };

    Node* first;
    Node* last;

    void copy(const QueueSeminars& other);
    void clear();

    public:

    QueueSeminars() : first(nullptr), last(nullptr) {}
    QueueSeminars(const QueueSeminars& other) : first(nullptr), last(nullptr) { copy(other); }
    QueueSeminars& operator = (const QueueSeminars& other);
    ~QueueSeminars() { clear(); }

    T& peek();
    void push_back(const T& data);
    bool pop();

    bool empty() { return first == nullptr; }
};

template <typename T>
void QueueSeminars<T>::copy(const QueueSeminars& other)
{
    for (Node* it = other.first; it != nullptr; it = it->next)
    {
        push_back(it->data);
    }
}

template <typename T>
void QueueSeminars<T>::clear()
{
    while (pop()) {}
}

template <typename T>
QueueSeminars<T>& QueueSeminars<T>::operator = (const QueueSeminars& other)
{
    if (this != other)
    {
        clear();
        copy(other);
    }
    
    return *this;
}

template <typename T>
T& QueueSeminars<T>::peek()
{
    assert(first != nullptr);
    return first->data;
}

template <typename T>
void QueueSeminars<T>::push_back(const T& data)
{
    Node* temp = new Node{data, nullptr};

    if (first == nullptr)
    {
        first = temp;
        last = temp;
    }
    else
    {
        last->next = temp;  
        last = temp;
    }
}

//const T&
//q.push_back(QueueSeminars(...));
//q.push_back(5);
//иначе не може 

template <typename T>
bool QueueSeminars<T>::pop()
{
    if (first == nullptr)
    {
        return false;
    }

    Node* temp = first;
    first = first->next;
    delete temp;

    if (first == nullptr)
    {
        last = nullptr;
    }
    
    return true;
}

#endif