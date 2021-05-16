#include <iostream>

struct TONode 
{
    double data;
    TONode *left, *mid, *right;
};

bool insert(TONode *&root, double x, double R) 
{
    if (root == nullptr) 
    {
        root = new TONode {x, nullptr, nullptr, nullptr};
        return true;
    }

    if (x <= root->data * (1 - R)) 
    {
        insert(root->left, x, R);
    } 
    else if (x >= root->data * (1 + R)) 
    {
        insert(root->right, x, R);
    } 
    else 
    {
        insert(root->mid, x, R);
    }

    return true;
}