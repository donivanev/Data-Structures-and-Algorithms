#include "ExpressionTree.h"

template <typename T>
bool ExpressionTree<T>::isLogicalOperator(std::string c)
{
    if (c == "&&" || c == "||") return true;
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
        return leftValue && rightValue;

    if (node->data == "||")
        return leftValue || rightValue;
}

template <typename T>
void ExpressionTree<T>::print()
{
    return printHelper(root);
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