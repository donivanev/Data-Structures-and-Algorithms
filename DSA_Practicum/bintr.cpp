#include <iostream>
#include <vector>
#include <queue>
#include <map>

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
    int countOfElements();
    int countOfEvens();
    int searchCount(bool (*pred)(const T&));
    int countLeaves();
    int maxLeaf();
    int max(int a, int b);
    int getElement(const char* s);
    int sumOfEvenLevelsWithoutLeftChild();
    void prettyPrint();
    std::vector<T> listLeaves(std::vector<T>& v);
    std::string findTrace(const T& x);
    int minDepth();
    T getAt(size_t i);
    std::pair<int, int> evenOddLeaves();
    BinTree<T>* copyTree(BinTree<T>* node);
    BinTree<T>* sumTrees(BinTree<T>* node, BinTree<T>* node2);

    private:

    Node* root;

    void printHelper(Node* node);
    T maxHelper(Node* node);
    bool areAllElementsEvenHelper(Node* node);
    bool hasWordHelper(Node* node, const char* str);
    bool matchWord(Node* node, const char* str);
    int heightHelper(Node* node);
    int countOfElementsHelper(Node* node);
    int countOfEvensHelper(Node* node);
    int searchCountHelper(Node* node, bool (*pred)(const T&));    
    int countLeavesHelper(Node* node);
    int maxLeafHelper(Node* node);
    int getElementHelper(Node* node, const char* s);
    int sumOfEvenLevelsWithoutLeftChildHelper(Node* node, int counter);
    void prettyPrintHelper(Node* node, int level);
    std::vector<T> listLeavesHelper(Node* node, std::vector<T>& v);
    std::string findTraceHelper(Node* node, const T& x, std::string& str, std::string trace);
    int minDepthHelper(Node* node, int level);
    T getAtHelper(Node* node, size_t i, std::queue<Node*>& q);
    std::pair<int, int> evenOddLeavesHelper(Node* node, int level);
    //BinTree<T>* sumTreesHelper(Node* node, BinTree<T>* node2);
    //BinTree<T>* sumTreesHelper(BinTree<T>* node, BinTree<T>* node2);
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

template <typename T>
int BinTree<T>::countOfElements()
{
    return countOfElementsHelper(root);
}

template <typename T>
int BinTree<T>::countOfElementsHelper(Node* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    
    return 1 + countOfElementsHelper(node->left) + countOfElementsHelper(node->right);
}

template <typename T>
int BinTree<T>::countOfEvens()
{
    return countOfEvensHelper(root);
}

template <typename T>
int BinTree<T>::countOfEvensHelper(Node* node)
{
    if (node == nullptr)
    {
        return 0;
    }

    return ((node->data % 2 == 1) ? 0 : 1) + countOfEvensHelper(node->left) + countOfEvensHelper(node->right);
}

bool isPrime(const int& number)
{
    if (number <= 1) return false;

    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return false; 
        }
    }
    
    return true;
}

template <typename T>
int BinTree<T>::searchCount(bool (*pred)(const T&))
{
    return searchCountHelper(root, pred);   
}

template <typename T>
int BinTree<T>::searchCountHelper(Node* node, bool (*pred)(const T&))
{
    if (node == nullptr)
    {
        return 0;
    }
    
    return (pred(node->data) == true ? 1 : 0) + searchCountHelper(node->left, pred) + searchCountHelper(node->right, pred);
}

template <typename T>
int BinTree<T>::countLeaves()
{
    return countLeavesHelper(root);
}

template <typename T>
int BinTree<T>::countLeavesHelper(Node* node)
{
    if (node == nullptr)
    {
        return 0;
    }

    int value = 0;

    if (node->left == nullptr && node->right == nullptr)
    {
        value = 1;
    }

    return value + countLeavesHelper(node->left) + countLeavesHelper(node->right);
}

template <typename T>
int BinTree<T>::max(int a, int b)
{
    if (a > b) return a;
    
    return b;
}

template <typename T>
int BinTree<T>::maxLeaf()
{
    return maxLeafHelper(root);
}

template <typename T>
int BinTree<T>::maxLeafHelper(Node* node)
{
    if (node == nullptr)
    {
        return INT32_MIN;
    }
    
    int leftMax = maxLeafHelper(node->left);
    int rightMax = maxLeafHelper(node->right);

    return max(node->data, max(leftMax, rightMax));
}

template <typename T>
int BinTree<T>::getElement(const char* s)
{
    return getElementHelper(root, s);
}

template <typename T>
int BinTree<T>::getElementHelper(Node* node, const char* s)
{
    if (node == nullptr)
    {
        return -1;
    }

    if (s[0] == '\0')
    {
        return node->data;
    }
    
    if (s[0] == 'L')
    {
        return getElementHelper(node->left, s + 1);
    }
    
    if (s[0] == 'R')
    {
        return getElementHelper(node->right, s + 1);
    }
}

template <typename T>
int BinTree<T>::sumOfEvenLevelsWithoutLeftChild()
{
    return sumOfEvenLevelsWithoutLeftChildHelper(root, 0);
}

template <typename T>
int BinTree<T>::sumOfEvenLevelsWithoutLeftChildHelper(Node* node, int counter)
{
    if (node == nullptr)
    {
        return 0;
    }
    
    if (counter % 2 == 0 && node->left == nullptr)
    {
        return 1 + sumOfEvenLevelsWithoutLeftChildHelper(node->left, counter + 1) + sumOfEvenLevelsWithoutLeftChildHelper(node->right, counter + 1); 
    }

    return 0 + sumOfEvenLevelsWithoutLeftChildHelper(node->left, counter + 1) + sumOfEvenLevelsWithoutLeftChildHelper(node->right, counter + 1); 
}

template <typename T>
void BinTree<T>::prettyPrint()
{
    return prettyPrintHelper(root, 0);
}

template <typename T>
void BinTree<T>::prettyPrintHelper(Node* node, int level)
{
    if (node == nullptr)
    {
        return;
    }
    
    std::cout << level << ":" << node->data << std::endl;
    prettyPrintHelper(node->left, level + 1);
    prettyPrintHelper(node->right, level + 1);
}

template <typename T>
std::vector<T> BinTree<T>::listLeaves(std::vector<T>& v)
{
    return listLeavesHelper(root, v);
}

template <typename T> 
std::vector<T> BinTree<T>::listLeavesHelper(Node* node, std::vector<T>& v)
{
    if (node == nullptr)
    {
        return std::vector<T>();
    }
    
    v.push_back(node->data);
    listLeavesHelper(node->left, v);
    listLeavesHelper(node->right, v);
}

/*template <typename T>
std::string BinTree<T>::findTrace(const T& x, std::map<int, std::string>& path)
{
    findTraceHelper(root, x, path, "");
    return path[x];
}

template <typename T>
std::string BinTree<T>::findTraceHelper(Node* node, const T& x, std::map<int, std::string>& path, std::string str)
{
    std::cout << node->data << " " << str << std::endl;
    if (node->left != nullptr)
    {
        findTraceHelper(node->left, x, path, str + "L");
    }
    if (node->right != nullptr)
    {
        findTraceHelper(node->right, x, path, str + "R");
    }
    
    path.insert({node->data, str});
}*/

template <typename T>
std::string BinTree<T>::findTrace(const T& x)
{
    std::string str;
    findTraceHelper(root, x, str, "");
    return str;
}

template <typename T>
std::string BinTree<T>::findTraceHelper(Node* node, const T& x, std::string& str, std::string trace)
{
    if (node->left != nullptr)
    {
        findTraceHelper(node->left, x, str, trace + "L");
    }
    if (node->right != nullptr)
    {
        findTraceHelper(node->right, x, str, trace + "R");
    }
    if (node != nullptr && node->data == x)
    {
        str = trace;
    }
}

template <typename T>
int BinTree<T>::minDepth()
{
    return minDepthHelper(root, 1);
}

template <typename T>
int BinTree<T>::minDepthHelper(Node* node, int level)
{
    if (node->left == nullptr && node->right == nullptr)
    {
        return level;
    }

    if (node->left != nullptr)
    {
        return minDepthHelper(node->left, level + 1);
    }
    
    return minDepthHelper(node->right, level + 1);
}

template <typename T>
T BinTree<T>::getAt(size_t i)
{
    std::queue<Node*> q;
    q.push(root);

    return getAtHelper(root, i, q);
}

template <typename T>
T BinTree<T>::getAtHelper(Node* node, size_t i, std::queue<Node*>& q)
{
    int counter = 0;

    while (!q.empty())
    {
        node = q.front();
        counter++;

        if (node->left != nullptr)
        {
            q.push(node->left);
        }
        
        if (node->right != nullptr)
        {
            q.push(node->right);
        }
        
        if (counter == i)
        {
            return node->data;
        }
        
        q.pop();
    }
}

template <typename T>
std::pair<int, int> BinTree<T>::evenOddLeaves()
{
    return evenOddLeavesHelper(root, 0);
}

//сумата на листата, намиращи се на четно разстояние от върха и произведението на тези намиращи се на нечетно
template <typename T>
std::pair<int, int> BinTree<T>::evenOddLeavesHelper(Node* node, int level)
{
    if (node == nullptr)
    {
        return std::make_pair(0, 1);
    }

    if (node->left == nullptr && node->right == nullptr)
    {
        if (level % 2 == 0)
        {
            return std::make_pair(node->data, 1);
        }
        else
        {
            return std::make_pair(0, node->data);
        }
    }

    std::pair<int, int> result1 = evenOddLeavesHelper(node->left, level + 1);
    std::pair<int, int> result2 = evenOddLeavesHelper(node->right, level + 1);
    return std::make_pair(result1.first + result2.first, result1.second * result2.second);
}

template <typename T>
BinTree<T>* BinTree<T>::copyTree(BinTree<T>* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    
    return new BinTree<T>(node->data, copyTree(node->left), copyTree(node->right));
}

/*
template <typename T>
BinTree<T>* BinTree<T>::sumTrees(BinTree<T>* root2)
{
    return sumTreesHelper(root, root2);
}

template <typename T>
BinTree<T>* BinTree<T>::sumTreesHelper(Node* node, BinTree<T>* node2)
{
    if (node == nullptr && node2 == nullptr)
    {
        return nullptr;
    }
    
    if (node == nullptr)
    {
        return copyTree(node2);
    }

    if (node2 == nullptr)
    {
        return copyTree(node);
    }
    
    return new BinTree<T>(node->data + node2->data, sumTreesHelper(node->left, node2->left), sumTreesHelper(node->right, node2->right));
}*/

template <typename T>
BinTree<T>* BinTree<T>::sumTrees(BinTree<T>* node, BinTree<T>* node2)
{
    if (node == nullptr && node2 == nullptr)
    {
        return nullptr;
    }
    
    if (node == nullptr)
    {
        return copyTree(node2);
    }

    if (node2 == nullptr)
    {
        return copyTree(node);
    }
    
    return new BinTree<T>(node->data + node2->data, sumTrees(node->left, node2->left), sumTrees(node->right, node2->right));
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

    //t.add(1, "");
    //t.add(2, "L");
    //t.add(3, "LL");
    //t.add(4, "LLL");
    //t.add(5, "LLLL");
    //t.add(6, "LLLLL");

    //t.print();
    //std::cout << std::endl;
    //std::cout << t.max();

    //std::cout << t.areAllElementsEven();

    //std::cout << "Height: " << t.height() << std::endl;

    //std::cout << "Count of elements: " << t.countOfElements() << std::endl;

    //std::cout << "Count of evens: " << t.countOfEvens() << std::endl;

    //std::cout << "Is prime: " << t.searchCount(isPrime) << std::endl;

    //std::cout << "Count of leafs: " << t.countLeaves() << std::endl;

    //std::cout << "Maximum leaf: " << t.maxLeaf() << std::endl;

    //std::cout << t.getElement("RRL") << std::endl;

    //std::cout << "Sum of even level without left child: " << t.sumOfEvenLevelsWithoutLeftChild() << std::endl;

    //t.prettyPrint();

    //std::vector<int> v;

    //t.listLeaves(v);

    //for (int value : v)
    //{
        //std::cout << value << " ";
    //}

    //std::cout << std::endl;

    //std::map<int, std::string> m;

    //std::cout << t.findTrace(4, m) << "__" << std::endl;
    //std::cout << t.findTrace(8, m) << "__" << std::endl;

    //for (const auto& x : m)
    //{
        //std::cout << x.first << " " << x.second << std::endl;    
    //}
    
    //std::cout << t.getAt(3);

    //std::cout << t.findTrace(4);

    //std::cout << t.minDepth();

    //std::pair<int, int> p = t.evenOddLeaves();
    //std::cout << p.first << " " << p.second;
    
    BinTree<int>* t1;
    t1->add(3, "");
    t1->add(5, "L");
    t1->add(7, "R");

    BinTree<int>* t2;
    t2->add(5, "");
    t2->add(1, "L");
    t2->add(9, "R");

    BinTree<int>* t3;

    t3->sumTrees(t1, t2);
}