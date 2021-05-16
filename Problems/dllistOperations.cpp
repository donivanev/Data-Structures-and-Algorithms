#include <iostream>
using namespace std;

template <class T>
class DLListOperations
{
    struct Node
    {
        T data;
        Node* prev;
        Node* next;

        Node();
        Node(T newData):data(newData), prev(nullptr), next(nullptr){}
    };

private:
    Node* first;
    void copy(const DLListOperations<T>& other);
    void clear();

public:
    DLListOperations();
    DLListOperations(const DLListOperations<T>& other);
    DLListOperations<T>& operator= (const DLListOperations<T>& other);
    DLListOperations<T>& operator+= (T data);
    ~DLListOperations();
    
    void print();
    void addToStart(T data);
    void addToEnd(T data);
    void addAfterRecursive(Node* curr, int insertAfter, T data);
    void addAfter(T data, int position);
    void deleteAtStart();
    void deleteAt(T data);
    void deleteAtEnd();
    void reverse();
    //Node* reverse(Node* first);
};

template <typename T>
DLListOperations<T>::DLListOperations():first(nullptr) {}

template <typename T>
DLListOperations<T>::DLListOperations(const DLListOperations<T>& other)
{
    copy(other);
}

template <typename T>
DLListOperations<T>& DLListOperations<T>::operator= (const DLListOperations<T>& other)
{
    if(this != &other)
    {
        clear();
        copy(other);

        return *this;
    }
}

template <typename T>
DLListOperations<T>& DLListOperations<T>::operator+= (T data)
{
    if (first == nullptr)
    {
        first = new Node(data);
        return *this;
    }
    
    Node* newNode = new Node(data);
    newNode->next = first;
    first->prev = newNode;
    first = first->prev;

    return *this;
}

template <typename T>
DLListOperations<T>::~DLListOperations()
{
    clear();
}

template <typename T>
void DLListOperations<T>::copy(const DLListOperations<T>& other)
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
void DLListOperations<T>::clear()
{
    Node* iter = first, *temp;

    while (iter != nullptr)
    {
        temp = iter;
        iter = iter->next;
        delete temp;
    }

    first = nullptr;
}

template <typename T>
void DLListOperations<T>::print()
{
    Node* curr = first;

    while (curr != nullptr)
    {
        cout << curr->data << " "; 
        curr = curr->next;
    }
}

template <typename T>
void DLListOperations<T>::addToStart(T data)
{
    Node* newNode = new Node(data); //създаваме нова кутия

    if(first == nullptr) // ако първата кутия сочи към nullptr
    {
        first = newNode; // пренасочваме указателя на първата кутия към този на новата
    }
    else
    {
        newNode->next = first; // пренасочваме next на новата кутия да сочи първата
        first->prev = newNode; // пренасочваме prev на първата кутия да сочи новата
        first = newNode;       // пренасочваме указателя на първата кутия към този на новата
    }
}

template <typename T>
void DLListOperations<T>::addToEnd(T data)
{
    Node* newNode = new Node(data); //създаваме нова кутия

    if(first == nullptr) // ако първата кутия сочи към nullptr
    {
        first = newNode; // пренасочваме указателя на първата кутия към този на новата
    }
    else
    {
        Node* curr = first;            // нека curr сочи към първата кутия
        while (curr->next != nullptr)  // 
        {                              //
            curr = curr->next;         // обхождаме всички кутии, докато не стигнем до последната
        }                              // curr вече сочи последната
        curr->next = newNode;          // пренасочваме next на последната кутия да сочи новата
        newNode->prev = curr;          // пренасочваме prev на новата кутия да сочи последната
    }
}

template <typename T>
void DLListOperations<T>::addAfterRecursive(Node* curr, int insertAfter, T data)
{
    if (curr == nullptr)
    {
        return;
    }
    if (curr->data == insertAfter)
    {
        Node* newData = new Node(data);
        if (curr->next != nullptr)
        {
            curr->next->prev = newData;
            newData->next = curr->next;
        }
        curr->next = newData;
        newData->prev = curr;
    }
    else
    {
        addAfterRecursive(curr->next, insertAfter, data);   
    }
}

template <typename T>
void DLListOperations<T>::addAfter(T data, int position)
{
    Node* newNode = new Node(data);

    if (position == 0)
    {
        addToStart(data);
    }
    
    Node* curr = first;
    --position;

    while (curr != nullptr && position != 0)
    {
        curr = curr->next;
        position--;
    }
    
    newNode->next = curr->next;
    curr->next->prev = newNode;
    newNode->prev = curr;
    curr->next = newNode;
}

template <typename T>
void DLListOperations<T>::deleteAtStart()
{
    Node* curr = first;

    if (first == nullptr || first->next == nullptr)
    {
        first = nullptr;
        return curr;
    }
    
    first = first->next;
    first->prev = nullptr;
    return curr;
}

template <typename T>
void DLListOperations<T>::deleteAt(T data)
{
    Node* curr = first;

    while (curr->next != nullptr)
    {
        curr = curr->next;

        if (curr->data == data)
        {
            curr = curr->next;
            break;
        }
    }

    if (curr != nullptr)
    {
        if (curr->next != nullptr)
        {
            curr->next->prev = curr->next;
        }
    }
    
    return curr;    
}

template <typename T>
void DLListOperations<T>::deleteAtEnd()
{
    Node* curr = first;

    if (first == nullptr || first->next == nullptr)
    {
        first = nullptr;
        return curr;
    }
    
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }

    return curr->prev->next = nullptr;
}

template <typename T>
void DLListOperations<T>::reverse()
{
    Node* curr = first, *prev = nullptr, *next = nullptr; 

    while (curr != nullptr) 
    { 
        // Store next 
        next = curr->next; 

        // Reverse current node's pointer 
        curr->next = prev; 

        // Move pointers one position ahead. 
        prev = curr; 
        curr = next; 
    } 

    first = prev; 
} 

/*template <typename T>
Node* DLListOperations<T>::reverse(Node* first) 
{ 
    if (first == nullptr || first->next == nullptr) return first; 

    Node* rest = reverse(head->next); 
    first->next->next = first; 
    first->next = nullptr; 

    return rest; 
}*/

int main()
{
    DLListOperations<int> dllist;

    dllist += 1;
    dllist += 2;
    dllist += 3;
    //dllist.addToStart(9);

    dllist.print();

    dllist.addAfter(4, 2);

    dllist.print();

    return 0;
}