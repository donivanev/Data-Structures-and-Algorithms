#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *next = nullptr, *previous = nullptr;

    Node();
    Node(T newData):data(newData){}
};

template <class T>
class DLList
{

    public:

    DLList():first(nullptr) {}
    DLList& operator+= (T data);
    T& operator[] (int index);
    int count(Node<T>* l, int x);
    Node<int>* range(int x, int y); 
    void removeAll(Node<T>*& l, const T& x);
    void print();
    
    private:

    Node<T> *first, *last;
};

template <class T>
DLList<T>& DLList<T>::operator+=(T data)
{
    if (first == nullptr)
    {
        first = new Node<T>(data);
        return *this;
    }
    
    Node<T>* newNode = new Node<T>(data);
    newNode->next = first;
    first->previous = newNode;
    first = first->previous;

    return *this;
}  

template <typename T>
T& DLList<T>::operator[](int index)
{
    Node<T>* curr = first;

    while (curr->next != nullptr && index != 0)
    {
        curr = curr->next;
        index--;
    }
    
    return curr->data;
}

template <typename T>
void DLList<T>::print()
{
    Node<T>* curr = first;

    while (curr != nullptr)
    {
        cout << curr->data << " "; 
        curr = curr->next;
    }
}

template <typename T>
int DLList<T>::count(Node<T>* l, int x)
{
    Node<T>* curr = l;
    int counter = 0;

    while (curr->next != nullptr)
    {
        if (curr->data == x)
        {
            counter++;
        }
        curr = curr->next;
    }
    
    return counter;
}

template <typename T>
Node<int>* DLList<T>::range(int x, int y)
{
    while (x <= y)
    {
        
    }
    
}

int main()
{

    DLList<int> dll;

    DLList<int> dllCount;
    int l = 3;
    dllCount+=l;
 
    dll+=1;
    dll+=4;
    dll+=4;
    dll+=7;
    dll+=7;
    dll+=7;

    dll.print();
    cout << dll.count((&dll[0]), 7);
    //int y = 9, x = 6;

    //cout << (x += !!y) << " ";
    //cout << x;

    int x = 5;
    unsigned y = 10;

    cout << ((x++ >= 5) && (--y < 10) && (x += 1) || (x += !!y) || (x -= y)) << endl;

    cout << endl << x;

    return 0;
}