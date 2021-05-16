#include <iostream>

template <class T>
struct Node 
{
    T data; 
    Node<T> *next;

    Node();
    Node(T data) : data(data), next(nullptr) {};
};

template <typename T>
//using f = std::function(int<int>);
T f(const T& x, const T& y)
{
    return x / y;
}

template <typename T>
void reduce(Node<T>* l)
{
    if (l == nullptr)
    {
        std::cout << "This list have no elements.";
    }
    
    if (l->next == nullptr)
    {
        std::cout << l->data;
    }

    Node<T>* curr = l;
    int counter = 0;

    while (curr->next != nullptr)
    {
        curr->next->data = f(curr->data, curr->next->data);
        curr = curr->next;
        counter++;
    }

}

template <typename T>
void addToEnd(Node<T>* &l, T data)
{
    Node<T>* newNode = new Node<T>(data);

    if (l == nullptr)
    {
        l = newNode;
        return;
    }

    Node<T>* curr = l;

    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    
    curr->next = newNode;
}

template <typename T>
void printElements(Node<T>* l)
{
    Node<T>* curr = l;

    while (curr != nullptr)
    {
        std::cout << curr->data << " ";
        curr = curr->next; 
    }
}

template <typename T>
void shuffle(Node<T>* l)
{
    
}

int main()
{
    Node<int>* list = nullptr;
    addToEnd(list, 1);
    addToEnd(list, 2);
    addToEnd(list, 3);
    //deleteNode(list);
    //printElements(list);

    Node<int>* list2 = nullptr;
    //addToEnd(list2, 124);
    //addToEnd(list2, 12);
    //addToEnd(list2, 4);
    addToEnd(list2, 30);
    addToEnd(list2, 5);
    addToEnd(list2, 3);
    //reduce(list2);

    //printElements(list2);

    return 0;
}