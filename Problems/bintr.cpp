#include <iostream>

template <class T>
class BinTree
{
    public:

    struct Node
    {
        int data;
        Node* left;
        Node* right;
        Node(int newData, Node* left = nullptr, Node* right = nullptr) : data(newData), left(left), right(right) {}
    };

    BinTree() : root(nullptr) {}

    void add(int element, const char* path);
    T max();
    int countElements();
    bool areAllElementsEven();
    void print();

    private:

    Node* root;
    void printHelper(Node* node);
    T maxHelper(Node* node);
    int countElementsHelper(Node* node, int counter);
    bool areAllElementsEvenHelper(Node* node);
};

template <typename T>
void BinTree<T>::add(int element, const char* path)
{
    if (root == nullptr)
    {
        root = new Node(element);
        return;
    }
    
    Node* curr = root;

    while (path[1])
    {
        if (path[0] == 'L')
        {
            curr = curr->left;
        }
        if (path[0] == 'R')
        {
            curr = curr->right;
        }
        path++;
    }

    if (path[0] == 'L' && curr->left == nullptr)
    {
        curr->left = new Node(element);
    }
    else if (path[0] == 'R' && curr->right == nullptr)
    {
        curr->right = new Node(element);
    }
}

template <typename T>
T BinTree<T>::max()
{
    return maxHelper(root);
}

template <typename T>
T BinTree<T>::maxHelper(Node* node)
{
    if (node == nullptr)
    {
        return INT32_MIN;
    }
    
    T leftMax = maxHelper(node->left);
    T rightMax = maxHelper(node->right);

    return std::max(node->data, std::max(leftMax, rightMax));
}

template <typename T>
int BinTree<T>::countElements()
{
    int counter = 0;
    return countElementsHelper(root, counter);
}

template <typename T>
int BinTree<T>::countElementsHelper(Node* node, int counter)
{
    if (node == nullptr)
    {
        return 0;
    }
       
    counter++;
    countElementsHelper(node->left, counter);
    counter++;
    countElementsHelper(node->right, counter);

    return counter;
}

template <typename T>
bool BinTree<T>::areAllElementsEven()
{
    return areAllElementsEvenHelper(root);
}

template <typename T>
bool BinTree<T>::areAllElementsEvenHelper(Node* node)
{
    if (node == nullptr)
    {
        return false;
    }

    int counter = 0;

    if (node->data % 2 == 0)
    {
        counter++;
    }
    
    areAllElementsEvenHelper(node->left);
    areAllElementsEvenHelper(node->right);

    counter == 0;
}

template <typename T>
void BinTree<T>::print()
{
    printHelper(root);
}

template <typename T>
void BinTree<T>::printHelper(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    std::cout << node->data << " ";
    printHelper(node->left);
    printHelper(node->right);
}

int main()
{
    BinTree<int> t;
    t.add(1, "");
    t.add(2, "L");
    t.add(3, "R");
    t.add(4, "LL");
    t.add(5, "LR");

    //std::cout << t.countElements();

    t.print();
    //std::cout << t.max();
}