  
#include <iostream>

template<class T>
class List 
{

public:
    struct Node 
    {
        T data;
        Node *next;
    };

private:
    Node *first;

public:
    List();
    ~List();

    void insetAtStart(T data);
    void print();
    void at(T data, int position);
    void sort();
    Node* getFirst();
    List<T>& unionList(List<T>& list);
    List<T>& differenceList(List<T>& list);
};

template<class T>
List<T>::List() : first(nullptr) { }

template<class T>
List<T>::~List() {
  List<T>::Node *curr = this->first;
  while (curr != nullptr) {
    List<T>::Node *tmp = curr;
    curr = curr->next;
    delete tmp;
  }
}

template<class T>
void List<T>::insetAtStart(T data) {
  List<T>::Node *newNode = new List<T>::Node();
  newNode->data = data;
  
  if (this->first == nullptr) {
    this->first = newNode;
    return;
  }

  newNode->next = this->first;
  this->first = newNode;
}


template<class T>
void List<T>::print() {
  List<T>::Node *curr = this->first;
  while (curr != nullptr) {
    std::cout << curr->data << " ";
    curr = curr->next;
  }
}

template<class T>
void List<T>::at(T data, int position) {
  List<T>::Node *newNode = new Node();
  newNode->data = data;

  if(position == 0) {
    this->insetAtStart(data);
    return;
  }

  List<T>::Node *curr = first;
  while (curr->next != nullptr && position != 1) {
    curr = curr->next;
    position--;
  }
  
  newNode->next = curr->next;
  curr->next = newNode;
}

template <typename T>
void List<T>::sort()
{
    Node* newFirst = nullptr;
    Node* curr = first;
    Node* prev = nullptr;
    Node* tempFirst = first;
    Node* newFirstCurr = nullptr;

    while (tempFirst != nullptr)
    {
        Node* currMin = curr, prevMin = prev;

        while (curr != nullptr)
        {
            if (currMin->data > curr->data)
            {
                currMin = curr;
                prevMin = prev;
            }
            
            prev = curr;
            curr = curr->next;
        }
        
        if (newFirst == nullptr)
        {
            newFirst = currMin;
            newFirstCurr = newFirst;
        }
        else
        {
            newFirstCurr->next = currMin;   
            newFirstCurr = newFirstCurr->next;
        }

        if (currMin == tempFirst)
        {
            tempFirst = tempFirst->next;
        }
        else
        {
            prevMin->next = prevMin->next->next;
        }

        first = newFirst;
    }
}

template <typename T>
List<T>::Node* List<T>::getFirst()
{
    return first;
}

template <typename T>
List<T>& List<T>::unionList(List<T>& list)
{
    List<T>::Node* secondFirst = list.getFirst();
}

template <typename T>
List<T>& List<T>::differenceList(List<T>& list)
{
    Node* secondCurr = list.getFirst();

    while (secondCurr != nullptr)
    {
        Node* firstCurr = first;
        Node* firstPrev = nullptr;

        while (firstCurr != nullptr)
        {
            if (secondCurr->data == firstCurr->data)
            {
                if (firstCurr == nullptr)
                {
                    first = first->next;
                }
                else
                {
                    firstPrev->next = firstCurr->next;    
                }
                
                delete firstCurr; 
                firstCurr = firstPrev->next;
            }
            firstPrev = firstCurr;
            firstCurr = firstCurr->next;
        }

        secondCurr = secondCurr->next;
    }
}

int main() {
  List<int> list;

  list.insetAtStart(3);
  list.insetAtStart(2);
  list.insetAtStart(1);
  
  return 0;
}