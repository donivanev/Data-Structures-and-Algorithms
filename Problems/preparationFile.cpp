#include <iostream>
#include <queue>
using namespace std;

template <typename T>
struct BinTree
{
    T data;
    BinTree<T>* left, *right;

    BinTree(T data, BinTree* left = nullptr, BinTree* right = nullptr) : data(data), left(left), right(right) {}
    ~BinTree()
    {
        if (left != nullptr)
        {
            delete left;
        }
        if (right != nullptr)
        {
            delete right;
        }
    }

    bool addLeft(T data)
    {
        if (left != nullptr)
        {
           return false; 
        }
        
        left = new BinTree<T>(data);
        return true;
    }

    bool addRight(T data)
    {
        if (right != nullptr)
        {
            return false;
        }
        
        right = new BinTree<T>(data);
        return true;
    }

    bool addNode(T data, std::string path)
    {
        if (path.size() == 1)
        {
            if (path[0] == 'L')
            {
                return addLeft(data);
            }
            else
            {
                return addRight(data);
            }
        }
        
        if (path[0] == 'L')
        {
            if (left == nullptr)
            {
                return false;
            }
            
            return left->addNode(data, path.substr(1));
        }
        else
        {
            if (right == nullptr)
            {
                return false;
            }
               
            return right->addNode(data, path.substr(1));
        }
    }

    void print()
    {
        std::cout << data << std::endl;

        if (left != nullptr)
        {
            left->print();
        }
        
        if (right != nullptr)
        {
            right->print();
        }
    }

    BinTree<T>* copyTree(BinTree<T>* node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        
        return new BinTree<int>(node->data, copyTree(node->left), copyTree(node->right));
    }

    pair<int, int> traverse(BinTree<T>* node, int level)
    {
        if (node == nullptr)
        {
            return make_pair(0, 1);
        }

        if (node->left == nullptr && node->right == nullptr)
        {
            if (level % 2 == 0)
            {
                return make_pair(node->data, 1);
            }
            else
            {
                return make_pair(0, node->data);   
            }   
        }
        
        pair<int, int> p = traverse(node->left, level + 1);
        pair<int, int> p2 = traverse(node->right, level + 1);
        return make_pair(p.first + p2.first, p.second * p2.second);
    }

    BinTree<T>* sumTrees(BinTree<T>* node, BinTree<T>* node2)
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

    bool isSymmetrical(BinTree<T>* node, BinTree<T>* node2)
    {
        if (node == nullptr && node2 == nullptr)
        {
            return true;
        }

        if (node == nullptr || node2 == nullptr)
        {
            return false;
        }
        
        return isSymmetrical(node->left, node2->right) && isSymmetrical(node->right, node2->left);
    }

    bool isSymmetrical(BinTree<T>* node)
    {
        return isSymmetrical(node->left, node->right);
    }

    bool isSymmetricalByValue(BinTree<T>* node, BinTree<T>* node2)
    {
        if (node ==  nullptr && node2 == nullptr)
        {
            return false;
        }
        
        if (node == nullptr || node2 == nullptr)
        {
            return true;
        }

        if (node->data == node2->data)
        {
            return true;
        }
        
        return isSymmetricalByValue(node->left, node2->right) && isSymmetricalByValue(node->right, node2->left);
    }

    bool isSymmetricalByValue(BinTree<T>* node)
    {
        return isSymmetricalByValue(node->left, node->right);
    }

    int countLeaves(BinTree<T>* node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        if (node->left == nullptr && node->right == nullptr)
        {
            return 1 + countLeaves(node->left) + countLeaves(node->right);
        }
        
        return 0 + countLeaves(node->left) + countLeaves(node->right);
    }

    /*BinTree<T>* deleteNode(struct node* root, int key)
    {
        
        if (root == nullptr) return root;
    
        // If the key to be deleted is smaller than the root's key, then it lies in left subtree
        if (key < root->key) root->left = deleteNode(root->left, key);
    
        // If the key to be deleted is greater than the root's key, then it lies in right subtree
        else if (key > root->key) root->right = deleteNode(root->right, key);
    
        // if key is same as root's key, then This is the node to be deleted
        else 
        {
            // node with only one child or no child
            if (root->left == nullptr) 
            {
                BinTree<T>* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) 
            {
                BinTree<T>* temp = root->left;
                delete root;
                return temp;
            }
    
            // node with two children: Get the inorder successor (smallest in the right subtree)
            BinTree<T>* temp = minValueNode(root->right);
    
            // Copy the inorder successor's content to this node
            root->key = temp->key;
    
            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }

        return root;
    }*/

    std::vector<std::string> levelWord(BinTree<T>* root)
    {
        std::vector<std::string> result;
        std::queue<BinTree<T>*> q;

        q.push(root);
        q.push(nullptr);

        std::string levelString;

        while (!q.empty())
        {
            BinTree<T>* crr = q.front();
            q.pop();

            if (crr == nullptr)
            {
                q.push(nullptr);
                result.push_back(levelString);
                levelString = "";
            }
            else
            {
                levelString.push_back(crr->data);
                if (crr->left) q.push(crr->left);
                if (crr->right) q.push(crr->right);
            }
        }

        return result;
    }

    //Дадено е произволно двоично дърво. Да се провери дали елементите на k-то ниво в дървото образуват палиндром.
    bool isPalindrome(int start, int end, std::string& str)
    {
        if (start >= end)
        {
            return true;
        }
        
        if (str[start] != str[end])
        {
            return false;
        }
        
        return isPalindrome(++start, --end, str);
    }

    bool levelWordPalindrome(BinTree<T>* root, int k)
    {
        //std::vector<std::string> result;
        std::queue<BinTree<T>*> q;
        int level = 0;

        q.push(root);
        q.push(nullptr);

        std::string levelString;

        while (!q.empty())
        {
            BinTree<T>* crr = q.front();
            q.pop();

            if (crr == nullptr)
            {
                q.push(nullptr);

                if (level == k && isPalindrome(0, levelString.length() - 1, levelString))
                {
                    return true;
                }
                else
                {
                    if (level > k)
                    {
                        return false;
                    }
                    else
                    {
                        levelString = "";
                    }
                }
                level++;
            }
            else
            {
                levelString.push_back(crr->data);
                if (crr->left) q.push(crr->left);
                if (crr->right) q.push(crr->right);
            }
        }

        return false;
    }

    int countOfLeaves(BinTree<T>* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        
        if (node->left == nullptr && node->right == nullptr)
        {
            return 1 + countOfLeaves(node->left) + countOfLeaves(node->right);
        }
        
        return 0 + countOfLeaves(node->left) + countOfLeaves(node->right);
    }

    bool find(BinTree<T> *root, const char *word) 
    {
        if (root == nullptr) return word[0] == '\0';

        return root->data == word[0] && (find(root->left, word + 1) || find(root->right, word + 1));
    }

    int countOfSubTreesOfValue(BinTree<T>* node, T value, int count)
    {
        if (node == nullptr)
        {
            return 0;
        }
        
        if (node->data == value)
        {
            count = 1;
        }
        
        return count + countOfSubTreesOfValue(node->left, value, count) + countOfSubTreesOfValue(node->right, value, count);
    }
};

template <typename T>
struct BinTree
{
    T data;
    BinTree<T>* left, *right;

    BinTree(T data, BinTree<T>* left = nullptr, BinTree<T>* right = nullptr) : data(data), left(left), right(right);
    ~BinTree()
    {
        if (left != nullptr)
        {
            delete left;
        }
        if (right != nullptr)
        {
            delete right;
        }
    }

    bool addLeft(T data)
    {
        if (left != nullptr)
        {
            return false;
        }
        
        left = new BinTree<T>(data);
        return true;
    }

    bool addRight(T data)
    {
        if (right != nullptr)
        {
            return false;
        }
        
        right = new BinTree<T>(data);
        return true;
    }

    bool addNode(T data, std::string str)
    {
        if (str.size() == 1)
        {
            if (str[0] == 'L')
            {
                return addLeft(data);
            }
            else
            {
                return addRight(data);
            }
        }
        
        if (str[0] == 'L')
        {
            if (left == nullptr)
            {
                return false;
            }

            return left->addNode(data, str.substr(1));
        }
        else
        {
            if (right == nullptr)
            {
                return false;
            }
            
            return right->addNode(data, str.substr(1));
        }
    }

    void print()
    {
        if (left != nullptr)
        {
            left->print();
        }
        
        std::cout << data << std::endl;

        if (right != nullptr)
        {
            right->print();
        }
    }

    BinTree<T>* copyTree(BinTree<T>* node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        
        return new BinTree<T>(node->data, copyTree(node->left), copyTree(node->right));
    }

    std::string levelWord(BinTree<T>* node)
    {
        std::queue<BinTree<T>*> q;
        std::string levelWord;
        q.push(node);
        q.push(nullptr);

        while (!q.empty())
        {
            BinTree<T>* curr = q.front();
            q.pop();

            if (curr == nullptr)
            {
                q.push(nullptr);
                std::cout << data << std::endl;
                levelWord = "";
            }
            else
            {
                levelWord.push_back(curr->data);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
    }

    bool match(BinTree<T>* node, const char* str)
    {
        if (node == nullptr)
        {
            return false;
        }
        
        bool isMatch = false;

        if (str[0] == node->data)
        {
            isMatch = matchWord(node, str);
        }
        
        ++str;
        bool leftMatch = match(node->left, str);
        bool rightMatch = match(node->right, str);

        return isMatch || leftMatch || rightMatch;
    }

    bool matchWord(BinTree<T>* node, const char* str)
    {
        if (node == nullptr)
        {
            return false;
        }

        if (node->left == nullptr && node->right == nullptr && str[1] == '\0')
        {
            return str[0] == node->data;
        }
        
        if (str[0] != node->data)
        {
            return false;
        }

        bool left = matchWord(node->left, ++str);
        bool right = matchWord(node->right, ++str);

        return left || right;
    }
};

int main()
{
    BinTree<int>* t = new BinTree<int>(3);

    //t->addNode(3, "");
    t->addNode(5, "L");
    t->addNode(8, "R");

    BinTree<int>* t2 = t2->copyTree(t);
    t2->print();

    BinTree<int>* t3 = nullptr;
    t3 = t3->sumTrees(t, t2);

    pair<int, int> p = t->traverse(t, 0);
    cout << p.first << " " << p.second << endl; 

    t3->print();

    //std::cout << t->isSymmetrical(t->left, t->right);
    std::cout << t->isSymmetrical(t) << std::endl;
    std::cout << t->isSymmetricalByValue(t) << std::endl;

    std::cout << t->countLeaves(t) << std::endl;

    BinTree<char>* t4 = new BinTree<char>('a');

    t4->addNode('b', "L");
    t4->addNode('c', "R");
    t4->addNode('d', "LL");
    t4->addNode('e', "LR");
    t4->addNode('e', "RL");
    t4->addNode('d', "RR");

    //t4->isPalindrome(t4);
    //std::cout << t4->levelWordPalindrome(t4, 2);
    std::cout << t4->countOfLeaves(t4) << std::endl;

    std::cout << t4->find(t4, "abz") << std::endl;

    std::cout << t4->countOfSubTreesOfValue(t4, 'b', 0);

    return 0;
}