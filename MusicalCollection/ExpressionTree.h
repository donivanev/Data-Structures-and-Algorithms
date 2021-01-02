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
    void addNode(std::string element, const char* path) 
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
    bool evaluateExpression();
    void print();

private:

    Node* root;
    bool evaluateExpressionHelper(Node* node);
    void printHelper(Node* node);
};

