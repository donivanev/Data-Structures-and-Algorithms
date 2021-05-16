#include <iostream>
#include <vector>
#include <stack>

template <class T>
struct TreeNode
{
    T data;
    std::vector<TreeNode*> children;
};

template <class T>
void printLeaves(TreeNode<T> *root)
{
    if(root == nullptr) 
    {
        return;
    }

    std::stack<TreeNode<T>*> s;
    s.push(root);

    while(!s.empty())
    {
        TreeNode<T>* current = s.top();
        s.pop();

        if(current->children.empty())
        {
            std::cout << current->data << " ";
        } 
        else 
        {
            for (auto child : current->children) 
            {
                s.push(child);
            }
        }
    }
}

template <class T>
TreeNode<T> * createTernaryTree (int n)
{
    TreeNode<T> *root = new TreeNode<T>;
    root->data = n;

    if(n <= 4)
    {
        return root;
    }

    root->children.push_back(createTernaryTree<T>(n - 1));
    root->children.push_back(createTernaryTree<T>(n / 2));
    root->children.push_back(createTernaryTree<T>(n / 3));

    return root;
}

//
//int main() {
//    int N;
//    std::cin >> N;
//
//    TreeNode<int> *tree = createTernaryTree<int>(10);
//
//    printLeaves(tree);
//
//    std::cout << "bla" << std::endl;
//    return 0;
//}
