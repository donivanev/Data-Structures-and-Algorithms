// 81992_exam2.cpp

#include <iostream>
#include <vector>
#include <queue>

struct Node
{
    int data;
    Node* left, * right;

    Node(int data, Node* left = nullptr, Node* right = nullptr) : data(data), left(left), right(right) {}
    ~Node()
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

    bool addLeft(int data)
    {
        if (left != nullptr)
        {
            return false;
        }

        left = new Node(data);
        return true;
    }

    bool addRight(int data)
    {
        if (right != nullptr)
        {
            return false;
        }

        right = new Node(data);
        return true;
    }

    bool addNode(int data, std::string path)
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

    int maxPath(Node* t)
    {
        return maxPathHelper(t, 0, 0, 0, true);
    }

    int maxPathHelper(Node* t, int curr, int sum, int max, int flag)
    {
        if (t == nullptr)
        {
            return 0;
        }

        if (t->data > curr)
        {
            if (flag)
            {
                sum += t->data;
                curr = t->data;
            }
        }
        else
        {
            flag = false;
            sum = 0;
        }

        if (t->left == nullptr && t->right == nullptr)
        {
            if (max < sum)
            {
                max = sum;
            }
        }

        return max + maxPathHelper(t->left, curr, sum, max, flag) + maxPathHelper(t->right, curr, sum, max, flag);
    }

    std::vector<int> average(Node* t)
    {
        std::vector<int> v;
        v = traverseByLevels(t);
        return v;
    }

    std::vector<int> traverseByLevels(Node* t)
    {
        std::queue<Node*> q;
        std::vector<int> v;
        int sum = 0, counter = 0;

        q.push(t);
        q.push(nullptr);

        while (!q.empty())
        {
            Node* curr = q.front();
            q.pop();

            if (curr == nullptr)
            {
                q.push(nullptr);
                if (sum == 0 || counter == 0)
                {
                    break;
                }
                v.push_back(sum / counter);
                sum = 0;
                counter = 0;
            }
            else
            {
                sum += curr->data;
                counter++;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }

        return v;
    }
};

struct CharNode
{
    char data;
    CharNode* left, * right;

    CharNode(int data, CharNode* left = nullptr, CharNode* right = nullptr) : data(data), left(left), right(right) {}
    ~CharNode()
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

    bool addLeft(int data)
    {
        if (left != nullptr)
        {
            return false;
        }

        left = new CharNode(data);
        return true;
    }

    bool addRight(int data)
    {
        if (right != nullptr)
        {
            return false;
        }

        right = new CharNode(data);
        return true;
    }

    bool addNode(int data, std::string path)
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

    std::vector<std::string> levelWords(CharNode* t)
    {
        std::queue<CharNode*> q;
        std::vector<std::string> vect;
        std::string levelWord;
        q.push(t);
        q.push(nullptr);

        while (!q.empty())
        {
            CharNode* curr = q.front();
            q.pop();

            if (curr == nullptr)
            {
                q.push(nullptr);
                if (levelWord == "")
                {
                    break;
                }
                vect.push_back(levelWord);
                levelWord = "";
            }
            else
            {
                levelWord.push_back(curr->data);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }

        return vect;
    }

    std::vector<std::string> verticalWords(CharNode* t, std::vector<std::string>& v1, std::vector<std::string>& v2, std::string word)
    {
        if (t == nullptr)
        {
            return std::vector<std::string>();
        }

        word.push_back(t->data);

        if (t->left == nullptr && t->right == nullptr)
        {
            //push in vector
            v1.push_back(word);
            word = "";
        }

        v1 = verticalWords(t->left, v1, v2, word);
        //v2 = verticalWords(t->right, v1, v2, word);
        return v1;
        
        /*std::vector<std::string> resultVector;

        for (std::string s : v1)
        {
            resultVector.push_back(s);
        }
        for (std::string s : v2)
        {
            resultVector.push_back(s);
        }

        return resultVector;*/
    }

    void mostFrequent(std::vector<std::string> v1, std::vector<std::string> v2)
    {

    }
};

int findHeight(Node* t)
{
    if (t == nullptr)
    {
        return 0;
    }

    int left = findHeight(t->left);
    int right = findHeight(t->right);

    return 1 + std::max(left, right);
}

int findMax(Node* t)
{
    if (t == nullptr)
    {
        return 0;
    }

    int leftMax = findMax(t->left);
    int rightMax = findMax(t->right);

    return std::max(t->data, std::max(leftMax, rightMax));
}

int main()
{
    //Task 1
    Node* tree = new Node(1);

    tree->addNode(2, "L");
    tree->addNode(1, "R");
    tree->addNode(3, "LL");
    tree->addNode(9, "RL");
    tree->addNode(8, "RR");
    
    //tree->print();
    std::cout << tree->maxPath(tree);

    //std::cout << findHeight(tree);

    std::cout << std::endl;

    //Task 2
    Node* tree2 = new Node(1);

    tree2->addNode(2, "L");
    tree2->addNode(5, "R");
    tree2->addNode(5, "LR");

    std::vector<int> vec = tree2->traverseByLevels(tree2);

    for (int x : vec)
    {
        std::cout << x << " ";
    }

    std::cout << std::endl;

    //Task 3
    CharNode* tree3 = new CharNode('c');

    tree3->addNode('a', "L");
    tree3->addNode('a', "R");
    tree3->addNode('c', "LL");
    tree3->addNode('a', "RL");
    tree3->addNode('c', "RR");
        
    //tree2->print();
    
    std::vector<std::string> verticalVector;
    std::vector<std::string> vect;
    verticalVector = tree3->verticalWords(tree3, verticalVector, vect, "");

    for (std::string s : verticalVector)
    {
        std::cout << s << std::endl;
    }

    std::vector<std::string> horizontalVector;
    horizontalVector = tree3->levelWords(tree3);

    for (std::string s : horizontalVector)
    {
        std::cout << s << " ";
    }

    return 0;
}
