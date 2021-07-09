#include <iostream>

template <class T>
class Queue
{
    struct Node
    {
        T data;
        Node* node;
    };

    private:

    Node* back;
    void copy(const Queue<T>& other);
    void clear();

    public:

    Queue();
    Queue(const Queue<T>& other);
    Queue& operator= (const Queue<T>& other);
    ~Queue();
};

template <typename T>
Queue<T>::Queue() : back(nullptr) {}

template <typename T>
void Queue<T>::copy(const Queue<T>& other)
{

}

template <typename T>
void Queue<T>::clear()
{
    
}

template <typename T>
Queue<T>::Queue(const Queue<T>& other)
{
    copy(other);
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
    if (this != &other)
    {
        copy(other);
        clear();
    }
    
    return *this;
}

template <typename T>
Queue<T>::~Queue()
{
    clear();
}