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
    bool areAllElementsEven();
    bool hasWord(const char* str);
    void print();
    int height(); 

    private:

    Node* root;

    void printHelper(Node* node);
    T maxHelper(Node* node);
    bool areAllElementsEvenHelper(Node* node);
    bool hasWordHelper(Node* node, const char* str);
    bool matchWord(Node* node, const char* str);
    int heightHelper(Node* node);
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
bool BinTree<T>::areAllElementsEven()
{
    return areAllElementsEvenHelper(root);
}

template <typename T>
bool BinTree<T>::areAllElementsEvenHelper(Node* node)
{
    if (node == nullptr)
    {
        return true;
    }

    return node->data % 2 == 0 
    && areAllElementsEvenHelper(node->left) 
    && areAllElementsEvenHelper(node->right);
}

template <typename T>
bool BinTree<T>::hasWord(const char* str)
{
    return hasWordHelper(root, str);
}

template <typename T>
bool BinTree<T>::hasWordHelper(Node* node, const char* str)
{
    if (node == nullptr)
    {
        return false;
    }

    bool isCurrentMatch = false;

    if (str[0] == node->data)
    {
        isCurrentMatch = matchWord(node, str);
    }

    str++;
    bool hasLeft = hasWordHelper(node->left, str);
    bool hasRight = hasWordHelper(node->right, str);

    return isCurrentMatch || hasLeft || hasRight;
}

template <typename T>
bool BinTree<T>::matchWord(Node* node, const char* str)
{
    if (node == nullptr)
    {
        return false;
    }

    if (node->left == nullptr && node->right == nullptr && str[1] == '\0')
    {
        return str[0] == node->data;
    }
    
    if (node->data != str[0])
    {
        return false;
    }
    
    bool leftMatch = matchWord(node->left, ++str);
    bool rightMatch = matchWord(node->right, ++str);

    return leftMatch || rightMatch;
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

template <typename T>
int BinTree<T>::height()
{
    return heightHelper(root);
}

template <typename T>
int BinTree<T>::heightHelper(Node* node)
{
    if (node == nullptr)
    {
        return 0;   
    }
    
    int leftDepth = heightHelper(node->left);  
    int rightDepth = heightHelper(node->right);  
      
    if (leftDepth > rightDepth) return (leftDepth + 1);  
    else return (rightDepth + 1); 
}

int main()
{
    BinTree<int> t;
    /*t.add(1, "");
    t.add(2, "L");
    t.add(3, "R");
    t.add(4, "LL");
    t.add(5, "LR");*/

    t.add(3, "");
    t.add(6, "L");
    t.add(1, "R");
    t.add(9, "LL");
    t.add(4, "LR");
    t.add(2, "RR");
    t.add(7, "RRL");
    t.add(8, "RRR");

    t.print();
    //std::cout << t.max();

    //std::cout << t.areAllElementsEven();

    std::cout << t.height();
}