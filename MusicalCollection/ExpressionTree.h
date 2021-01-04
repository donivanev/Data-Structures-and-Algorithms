#pragma once
#include <iostream>

//A class that holds a binary tree which is used to calculate a logical expression

template <typename T>
class ExpressionTree
{
public:

    struct Node
    {
        std::string data;
        Node* left, * right;
        Node(std::string newData, Node* left = nullptr, Node* right = nullptr) : data(newData), left(left), right(right) {};
    };

    ExpressionTree() : root(nullptr) {}

    bool isLogicalOperator(std::string c);
    bool toBool(std::string s);
    void addNode(std::string element, const char* path);
    bool evaluateExpression();
    void print();
    void clearTree();

private:

    Node* root;
    bool evaluateExpressionHelper(Node* node);
    void printHelper(Node* node);
    void clearTreeHelper(Node* node);
};

