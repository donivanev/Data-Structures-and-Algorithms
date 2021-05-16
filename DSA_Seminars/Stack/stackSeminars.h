#ifndef _STACK_H_
#define _STACK_H_

#include <stdexcept>

template <typename T>
class stackSeminars
{
private:

    struct Node
    {
        T data;
        Node* next;
    };

    Node* s_top;

public:

    stackSeminars();
    stackSeminars(const stackSeminars<T>& other) = delete;
    stackSeminars& operator = (const stackSeminars<T>& other) = delete;
    ~stackSeminars();

    T& top();
    bool pop();
    void push(const T& data);

    inline bool empty() { return !s_top; };
};

template <typename T>
stackSeminars<T>::stackSeminars() : s_top(nullptr) {}

template <typename T>
stackSeminars<T>::~stackSeminars()
{
    while (!empty())
    {
        pop();
    }

    //while (pop()) {}    
}

template <typename T>
bool stackSeminars<T>::pop()
{
    if (empty()) return false;
    
    Node* curr = s_top;
    s_top = s_top->next;
    delete curr;

    return true;
}

template <typename T>
T& stackSeminars<T>::top()
{
    if (empty())
    {
        throw std::runtime_error("Cannot add element in empty stack.");
    }
    
    return s_top->data;
}

template <typename T>
void stackSeminars<T>::push(const T& data)
{
    Node* curr = new Node();

    curr->data = data;
    curr->next = s_top;

    s_top = curr;
}

#endif