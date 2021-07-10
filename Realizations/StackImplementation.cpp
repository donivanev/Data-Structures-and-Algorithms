#include <iostream>

template <class T>
class Stack
{
    struct Node
    {
        T data;
        Node* next;
    }

    private:

    Node* back;
    void copy(const Stack<T>& other);
    void clear();

    public:

    Stack();
    Stack(const Stack<T>& other);
    Stack& operator=(const Stack<T>& other);
    ~Stack();

    inline bool empty() { return !back; };
    T& top();
    bool pop();
    void push(const T& data);
};

template <typename T>
Stack<T>::Stack() : back(nullptr) {}

template <typename T>
void Stack<T>::copy(const Stack<T>& other)
{
    
}

template <typename T>
void Stack<T>::clear()
{
    while (!empty()) pop();
}

template <typename T>
T& Stack<T>::top()
{
    if (empty())
    {
        throw std::runtime_error("Cannot add element in empty stack.");
    }
    
    return back->data;
}

template <typename T>
bool Stack<T>::pop()
{
    if (empty()) return false;
    
    Node* curr = back;
    back = back->next;
    delete curr;

    return true;
}

template <typename T>
void Stack<T>::push(const T& data)
{
    Node* curr = new Node();
    curr->data = data;

    curr->next = back;
    back = curr;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& other)
{
    copy(other);
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
    if (this != &other)
    {
        copy(other);
        clear()
    }
    
    return *this;
}

template <typename T>
Stack<T>::~Stack()
{
    clear();
}