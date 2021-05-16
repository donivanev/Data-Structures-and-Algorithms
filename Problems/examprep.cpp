#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <functional>

template<class T>
struct Node
{
    T data;
    Node *next;
};

//bool (* func)(int)
using pred = std::function<bool(int)>;
void split(Node<int>* L, pred p, Node<int>* &L1, Node<int>* &L2)
//1 2 3 4 5 6 7
//p ::= even
//L1: 1 3 5 7 L2: 2 4 6
{
    L1 = nullptr;
    L2 = nullptr;
    
    if (L == nullptr)
    {
        return;
    }
    
    Node<int> *L1last = nullptr, *L2last = nullptr;
    
    while(L != nullptr)
    {
        if(p(L->data))
        {
            if (L1 == nullptr)
            {
                L1last = L1 = new Node<int>{L->data, L1};
            } 
            else 
            {
                L1last->next = new Node<int>{L->data, nullptr};
                L1last = L1last->next;
            }
        }
        else
        {
            if (L2 == nullptr)
            {
                L1last = L2 = new Node<int>{L->data, nullptr};
            } 
            else 
            {
                L2last->next = new Node<int>{L->data, nullptr};
                L2last = L2last->next;
            }
        }

        L = L->next;
    }

    return;
}

template<typename T>
int count(Node<T> *first, T elem)
{
    Node<T> *curr = first;
    int counter = 0;
    while(curr)
    {
        if(curr->data == elem)
        {
            counter++;
        }
        curr = curr->next;
    }
    return counter;
}

/*
    input: 2 2 2 2 2
    result: []
    
    input: 2 1 2 1 3 2 1 2 1 
    result: 3
*/
template<class T>
void remove(Node<T> *&list, const T& x){
/*
   2 2 2 2 2 2 2 2 2 2 8 3 4 5 6
   
                      /|\
   -(2)
*/
    if(list == nullptr)  return;
    
    Node<T> *tmp;
    while (list != nullptr && list->data == x)
    {    
        tmp = list;
        list = list->next;
        delete tmp;
    }

    Node<T> *crr = list;

    while (crr->next != nullptr)
    {
       if (crr->next-> data == x)
       {    
           tmp = crr->next->next;
           delete crr->next;
           crr->next = tmp;
       } 
       else 
       {
            crr = crr->next;
       }
    }
}

template<class T>
void removeDuplicates(Node<T> *&list){
    //2 2 2 2 2 2 4 4 4 4 4 4 3 8 8 8 8  9 9 9 
    
    while (list != nullptr && count(list->data, list) > 1)
    {
        remove (list, list->data);
    }
    
    if (list == nullptr)
    {
        return;
    }
    
    Node<T> *crr = list;

    while (crr->next != nullptr)
    {
        if (count(crr->next->data, crr->next) > 1)
        {
            remove (crr->next, crr->next->data);
        }
    }
}

template<class T>
bool duplicate (Node<T> *first)
{
    while(first)
    {
        if(count(first, first->data) > 1)
        {
            return true;   
        }

        first = first->next;
    }

    return false;
}

template<class T>
Node<T>* reverseFib(Node<T>* first)
{
    if (first == nullptr)
    {
        return nullptr;
    }
    
    if (first->next == nullptr)
    {
        return new Node<T>{first->data, nullptr};
    }
    
    Node<T> *result = nullptr;
    
    result = new Node<T> {first->data, nullptr};
    while(first->next->next != nullptr)
    {
        if((first->next->data + first->data) != first->next->next->data)
        {
            return nullptr;
        }

        first = first->next;
        result = new Node<T> {first->data, result};
    }

    result = new Node<T> {first->next->data, result};

    return result;
}

Node<int>* createFibList (unsigned int n)
{
    Node<int> *firstFib = new Node<int> {0, nullptr};
    Node<int> *lastFib = firstFib;
    // 0 1 1 2 3 5 8 ....
    int a = 0, b = 1;
    // std::cout<<a<<" "<<b<<" ";
    firstFib->data = 0;
    firstFib->next = new Node<int> {1, nullptr};
    lastFib = firstFib->next;

    for (int i = 2; i < n; i++)
    {
        //std::cout<<a+b<<" ";
        lastFib->next = new Node<int> {a + b, nullptr};
        lastFib = lastFib->next;
        int save = a + b;
        a = b;
        b = save;
    }

    return firstFib;
}

template<class T>
void printList(Node<T>* first)
{
    while(first!=nullptr)
    {
        std::cout<<first->data<<" ";
        first=first->next;
    }
    std::cout<<std::endl;
}

void testFibList()
{    
    printList(createFibList(2));
    printList(createFibList(5));
    printList(createFibList(11));
    printList(reverseFib(createFibList(11)));
    printList(createFibList(8));
    printList(createFibList(0));
    printList(createFibList(1));   
}

bool correct(const char* input)
{
    //<f>lorem<m>ips/umf</m>dolor</f><m><f></f><b></b><f></f></m>
    
    std::stack<char> stack;

    while(input[0] != '\0')
    {
        std::cout << input[0] << " ";
        if(input[0] == '<')
        {
            input++;

            if(input[0] == '/')
            {
                input++;

                if(stack.size() > 0 && input[0] == stack.top())
                {
                    stack.pop();
                }
                else 
                {
                    return false;
                }
            } 
            else 
            {
                stack.push(input[0]);
            }
        }
        ++input;
    }
    
    return stack.size() == 0;
}

//New test
template<class T>
void remDuplicates(Node<T> *&first)
{
    bool found = false;
    Node<T> *curr = first;

    while(curr != nullptr)
    {
        if(curr->next != nullptr && first->data == curr->next->data) 
        {
            found = true;
            Node<T> *tmp = curr->next;
            curr->next = curr->next->next;
            delete tmp;
        }
        curr = curr->next;
    }

    if(found && first != nullptr)
    {
        Node<T> *tmp = first;
        first = first->next;
        delete tmp;
    }
}

int main ()
{

    //testFibList();
    //std::cout << correct ("<f></f><a><b><c></c></a></b>") << std::endl;
    std::cout << correct ("<f>abc<m>cba</m></f>") << std::endl;
    return 0;
    
}