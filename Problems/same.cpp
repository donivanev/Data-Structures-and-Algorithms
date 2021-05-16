#include <iostream>
#include <stack>
#include <queue>

template <typename T>
struct Node
{
    T data;
    Node* next;

    Node();
    Node(T data) : data(data), next(nullptr) {} ;
};

std::queue<int> returnQueue(std::stack<int>& s)
{
    std::queue<int> q;
    std::stack<int> reversedStack;
    int index = 0;

    while (!s.empty())
    {
        reversedStack.push(s.top());
        s.pop();
    }

    while (!reversedStack.empty())
    {
        if (index % 2 == 0)
        {
            q.push(reversedStack.top());
        }
        
        s.push(reversedStack.top());
        reversedStack.pop();
        index++;
    }
    
    return q;
}

template <typename T>
void fillgaps(Node<T>* first)
{
    Node<T>* curr = first;

    while (curr->next != nullptr)
    {
        if (curr->next->data - curr->data > 1)
        {
            curr->next = new Node<int> {curr->data + 1, curr->next};
        }
    
        curr = curr->next;
    }
}

template <typename T>
void removedups(Node<T>* first)
{
    if (first == nullptr)
    {
        return;
    }
    
    Node<T>* temp, *curr = first;

    while (curr->next != nullptr)
    {
        if (curr->data == curr->next->data)
        {
            temp = curr->next->next;
            delete curr->next;
            curr->next = temp;
        }
        else
        {
            curr = curr->next;   
        }
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
void reverse(Node<T>* &first)
{
    Node<T>* curr = first, *next = nullptr, *prev = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    first = prev;
}

template <typename T>
void mirror(Node<T>* l)
{
    Node<T>* curr = l, *copy = nullptr;

    while (curr->next != nullptr)
    {
        addToEnd(copy, curr->data);
        curr = curr->next;
    }

    addToEnd(copy, curr->data);
    reverse(copy);
    
    curr->next = copy;
    printList(l);
}

template <typename T>
void printList(Node<T>* l)
{
    Node<T>* curr = l;

    while (curr != nullptr)
    {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
}

template <typename T>
bool dupsub(Node<T>* first, int k)
{
    if (first == nullptr)
    {
        return false;
    }
    
    Node<T>* curr = first;

    while (curr->next != nullptr)
    {
        Node<T>* subcurr = curr->next;

        while(subcurr != nullptr) 
        {
            Node<T>* temp1 = curr;
            Node<T>* temp2 = subcurr;
            int counter = k;
            while (temp1->data == temp2->data)
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
                k--;   
            }
            if (counter == 0)
            {
                return true;
            }
            subcurr = subcurr->next;
        }

        curr = curr->next;
    }
}

int main()
{
    Node<int>* list = nullptr;
    addToEnd(list, 1);
    addToEnd(list, 2);
    addToEnd(list, 2);
    addToEnd(list, 3);
    addToEnd(list, 5);
    addToEnd(list, 5);

    //removedups(list);
    //printList(list);

    Node<int>* list2 = nullptr;
    addToEnd(list2, 1);
    addToEnd(list2, 2);
    addToEnd(list2, 3);

    mirror(list2);
    //reverse(list2);

    //printList(list2);

    return 0;
}