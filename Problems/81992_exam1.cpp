#include <iostream>
#include <stack>

template <class T>
struct Node 
{
    T data; 
    Node<T> *next;

    Node();
    Node(T data) : data(data), next(nullptr) {};
};

/*template <class T>
struct NodeStack 
{
    std::stack<T> s; 
    NodeStack<T> *next;

    NodeStack();
    NodeStack(std::stack<T> stack) : s(stack), next(nullptr) {};
};*/

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

    while (curr->next != nullptr)
    {
        curr->next->data = f(curr->data, curr->next->data);
        curr = curr->next;
    }

    printElements(curr);
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
    int len = length(l) / 2;
    int len2 = length(l) - len;
    reverseList(l);

    Node<T>* curr = l;

    while (len != 0)
    {
        std::cout << curr->data << " ";
        curr = curr->next; 
        len--;
    }

    reverseList(l);
    Node<T>* curr2 = l;

    while (len2 != 0)
    {
        std::cout << curr2->data << " ";
        curr2 = curr2->next; 
        len2--;
    }
}

template <typename T>
int length(Node<T>* l)
{
    Node<T>* curr = l;
    int len = 0;

    while (curr != nullptr)
    {
        len++;
        curr = curr->next;
    }
    
    return len;
}

template <typename T>
void addStackToEnd(Node<T>* &l, std::stack<T> stack)
{
    Node<std::stack<T>>* newStackNode = new Node<std::stack<T>>(stack);

    if (l == nullptr)
    {
        l = newStackNode;
        return;
    }

    Node<T>* curr = l;

    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    
    curr->next = newStackNode;
}

template <typename T>
void equalize(Node<std::stack<T>>* L)
{
    std::stack<int> stack;
    Node<std::stack<T>>* curr = L;

    while (curr != nullptr)
    {
        if (curr->data.size() - curr->next->data.size() > 1)
        {
            while (curr->data.size() - curr->next->data.size() > 1)
            {
                curr->next->data.push(curr->data.top());
                curr->data.pop();
            }
        }
        curr = curr->next;
    }
}

template <typename T>
void reverseList(Node<T>* &l)
{
    Node<T>* curr = l; 
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    l = prev;
}

int main()
{
    Node<int>* list = nullptr;
    addToEnd(list, 1);
    addToEnd(list, 2);
    addToEnd(list, 3);
    //printElements(list);

    //Problem 1
    Node<int>* list2 = nullptr;
    addToEnd(list2, 30);
    addToEnd(list2, 5);
    addToEnd(list2, 3);
    reduce(list2);
    std::cout << std::endl;

    //Problem 3
    Node<int>* list3 = nullptr;
    addToEnd(list3, 30);
    addToEnd(list3, 5);
    addToEnd(list3, 3);
    addToEnd(list3, 7);
    addToEnd(list3, 22);
    shuffle(list3);
    std::cout << std::endl;

    //Problem 2
    Node<int>* list4 = nullptr;
    std::stack<int> s;
    s.push(1); s.push(2); s.push(3); s.push(4); s.push(5); 
    std::stack<int> s2;
    s2.push(6); s2.push(7);  
    std::stack<int> s3;
    s3.push(8); s3.push(9); s3.push(10); s3.push(11);   
    std::stack<int> s4;
    s4.push(12);
    //addStackToEnd(list4, s);
    //addStackToEnd(list4, s2);
    //addStackToEnd(list4, s3);
    //addStackToEnd(list4, s4);
    //equalize();

    return 0;
}