#include <iostream>

template <class T>
struct Node
{
    T data;
    Node<T> *prev;
    Node<T> *next;
};

template <class T>
class DLList
{
    private:
    Node<T> *first;

    public:
    DLList():first(nullptr) {};

    void add(T value, int position)
    {
        if(this->first == nullptr)
        {
            this->first = new Node<T>(value);
            first->next = nullptr;
            first->prev = nullptr;
            return;
        }

        Node<T> *curr = this->first;
        while(position != 0 && curr->next == nullptr)
        {
            curr = curr->next;
            position--;
        }

        Node<T> *temp = curr->next;
        Node<T> *newNode = new Node<T>(value);

        curr->next = newNode;
        newNode->prev = curr;
        newNode->next = temp;

        if(temp != nullptr)
        {
            temp->prev = newNode;
        }
    }
};

int main()
{
    DLList<int> list;

    list.add(2, 1);
    list.add(1, 2);

    return 0;
}