#include "ExpressionTree.h"

template <typename T>
bool ExpressionTree<T>::isLogicalOperator(std::string s)
{
    if (s == "&&" || s == "||")
    {
        return true;
    }

    return false;
}

template <typename T>
bool ExpressionTree<T>::toBool(std::string s)
{
    if (s == "T")
    {
        return true;
    }

    return false;
}

template <typename T>
void ExpressionTree<T>::addNode(std::string element, const char* path)
{
    if (root == nullptr)
    {
        root = new Node(element);
        return;
    }

    Node* curr = root;

    while (path[1])
    {
        if (path[0] == 'L') curr = curr->left;
        if (path[0] == 'R') curr = curr->right;
        path++;
    }

    if (path[0] == 'L' && curr->left == nullptr)       curr->left = new Node(element);
    else if (path[0] == 'R' && curr->right == nullptr) curr->right = new Node(element);
}

template <typename T>
bool ExpressionTree<T>::evaluateExpression()
{
    return evaluateExpressionHelper(root);
}

template <typename T>
bool ExpressionTree<T>::evaluateExpressionHelper(Node* node)
{
    if (node == nullptr)
    {
        return false;
    }

    if (!node->left && !node->right)
    {
        return toBool(node->data);
    }

    int leftValue = evaluateExpressionHelper(node->left);
    int rightValue = evaluateExpressionHelper(node->right);

    if (node->data == "&&")
    {
        return leftValue && rightValue;
    }

    if (node->data == "||")
    {
        return leftValue || rightValue;
    }
}

template <typename T>
void ExpressionTree<T>::print()
{
    printHelper(root);
}

template <typename T>
void ExpressionTree<T>::printHelper(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    printHelper(node->left);
    std::cout << node->data;
    printHelper(node->right);
}

template <typename T>
void ExpressionTree<T>::clearTree()
{
    clearTreeHelper(root);
    root = nullptr;
}

template <typename T>
void ExpressionTree<T>::clearTreeHelper(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    clearTreeHelper(node->left);
    clearTreeHelper(node->right);

    delete node;
    node = nullptr;
}