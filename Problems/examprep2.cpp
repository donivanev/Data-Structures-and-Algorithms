#include <iostream>
#include <string>
#include <utility>

template <typename T>
struct TreeNode
{
    T data;
    TreeNode<T> *left, *right;
    
    TreeNode(const T& data, TreeNode<T> *left = nullptr, TreeNode<T> *right = nullptr) : data(data), left(left), right(right) {}
    ~TreeNode()
    {
        if (left != nullptr) delete left;
        if (right != nullptr) delete right;
    }

    bool addLeft(const T& data)
    {
        if (left != nullptr)
        {
            return false;
        }

        left = new TreeNode<T>(data);
        return true;
    }

    bool addRight(const T& data)
    {
        if (right != nullptr)
        {
            return false;
        }

        right = new TreeNode<T>(data);
        return true;
    }

    bool hasLeft() const
    {
        return left != nullptr;
    }

    bool hasRight() const
    {
        return right != nullptr;
    }
    
    bool addNode(const std::string path, const T& data)
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
            if (!hasLeft())
            {
                return false;
            }
            
            return left->addNode(path.substr(1), data);
        }
        else
        {
            if (!hasRight())
            {
                return false;
            }
            
            return right->addNode(path.substr(1), data);
        }
    }

    void print()
    {
        if (hasLeft())
        {
            left->print();
        }

        std::cout << data << " ";

        if (hasRight())
        {
            right->print();
        }
    }

    bool isLeaf() const
    {
        return !hasLeft() && !hasRight();
    }

    std::pair<int, int> traverse(const TreeNode<int>* root, const int depth = 0)
    {
        if (root == nullptr)
        {
            return make_pair(0, 1);
        }

        if (root->isLeaf())
        {
            if (depth % 2 == 0)
            {
                return make_pair(root->data, 1);    
            }
            else
            {
                return make_pair(0, root->data);   
            }
        }

        std::pair<int, int> result = traverse(root->left, depth + 1);
        std::pair<int, int> result2 = traverse(root->right, depth + 1);
        return make_pair(result.first + result2.first, result.second * result.second);
    }

    TreeNode<int>* copyTree(const TreeNode<int> *node)
    {
        if(node == nullptr) 
        {
            return nullptr;
        }
        
        return new TreeNode<int>(node->data, copyTree(node->left), copyTree(node->right));
    }
 
    TreeNode<int>* sumTrees(const TreeNode<int> *node1, const TreeNode<int> *node2)
    {
        if(node1 == nullptr && node2 == nullptr) 
        {
            return nullptr;
        }

        if(node1 == nullptr)
        {
            return copyTree(node2);
        }

        if(node2 == nullptr)
        {
            return copyTree(node1);
        }
        
        return new TreeNode<int>(node1->data + node2->data, sumTrees(node1->left, node2->left), sumTrees(node1->right, node2->right));
    }
};

int main()
{
    TreeNode<int> t(5);
    t.addLeft(3);
    t.addRight(6);
    t.addNode("LR", 4);
    t.print();

    return 0;
}