#include <iostream>
using namespace std;

template <class T>
class LListPracticum
{
    struct Node
    {
        T data;
        Node* next;
    };

    private:
        Node* first;

    public:
        LListPracticum();
        LListPracticum(const LListPracticum& other);
        LListPracticum operator= (const LListPracticum& other);
        ~LListPracticum();
        void addToStart(T data);
        void addToEnd(T data);
        void addAt(T data, int position);
        void deleteAt(int position);
        int longestIncreasing();
        void reverse(); 
        void print();

};

template <typename T>
LListPracticum<T>::LListPracticum():first(nullptr) {}

template <typename T>
LListPracticum<T>::~LListPracticum() 
{
    Node* iter = first, *temp;

    while (iter != nullptr)
    {
        temp = iter;
        iter = iter->next;
        delete temp;
    }
    
    //first = nullptr; няма смисъл ако кода се имплементира директно в деструктора
}

template <typename T>
void LListPracticum<T>::addToStart(T data)
{
    Node* newNode = new Node();
    newNode->data = data;

    if(first == nullptr)
    {
        first = newNode;
        return;
    }
     
    newNode->next = first;
    first = newNode;
}

template <typename T>
void LListPracticum<T>::addToEnd(T data)
{
    Node* newNode = new Node();
    newNode->data = data;

    if (first == nullptr)
    {
        first = newNode;
        return;
    }

    Node* curr = first;

    while (curr->next != nullptr)
    {
        curr = curr->next;
    }

    curr->next = newNode;
}

template <typename T>
void LListPracticum<T>::addAt(T data, int position)
{
    Node* newNode = new Node();
    newNode->data = data;

    if (position == 0)
    {
        addToStart(data);
    }
    
    Node* curr = first;

    while (curr->next != nullptr && position != 0)
    {
        curr = curr->next;
        position--;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    //curr->next = newNode;
    //newNode->next = curr->next->next;
    //curr->next->next вече е nullptr
}

template <typename T>
void LListPracticum<T>::deleteAt(int position)
{
    Node* curr = first, *temp;

    while (curr->next != nullptr && position != 0)
    {
        temp = curr;
        curr = curr->next;
        position--;
    }

    temp->next = curr->next;
    delete temp;
}

template <typename T>
int LListPracticum<T>::longestIncreasing()
{
    Node* curr = first->next, *prev = first;
    int maxLength = 1, currentLength = 1;

    if (first == nullptr)
    {
        return 0;
    }

    while (curr->next != nullptr)
    {
        if (curr->data > prev->data)
        {
            currentLength++;
        }
        else
        {
            maxLength = currentLength;
            currentLength = 0;
        }   
        curr = curr->next;
        prev = prev->next;
    }

    if (maxLength == currentLength)
    {
        maxLength = currentLength;
    }

    return maxLength;
}

template <typename T>
void LListPracticum<T>::print()
{
    Node* curr = first;

    while (curr != nullptr)
    {
        cout << curr->data << " "; 
        curr = curr->next;
    }
}

int main()
{
    LListPracticum<int> llist;

    llist.addToStart(1);
    llist.addToStart(2);
    llist.addToStart(3);

    llist.addToEnd(5);
    llist.addToEnd(6);
    llist.addToEnd(7);

    llist.addAt(11, 2);
    llist.addAt(12, 3);
    llist.addAt(13, 4);

    llist.print();

    return 0;
}