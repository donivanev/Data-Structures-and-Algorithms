#include <iostream>
#include <queue>
#include <vector>

struct Node 
{
    char data;
    Node *left, *right;
};

std::vector<std::string> pathsToLeaves(Node *pNode, std::vector<std::string> vector);

std::vector<std::string> levelWord(Node *root) 
{
    std::vector<std::string> result;
    std::queue<Node *> bfsQueue;

    bfsQueue.push(root);
    bfsQueue.push(nullptr);

    std::string levelString;

    while (!bfsQueue.empty()) 
    {
        Node *crr = bfsQueue.front();
        bfsQueue.pop();

        if (crr == nullptr) 
        {
            bfsQueue.push(nullptr);
            result.push_back(levelString);
            levelString = "";
        } 
        else 
        {
            levelString.push_back(crr->data);
            if (crr->left) bfsQueue.push(crr->left);
            if (crr->right) bfsQueue.push(crr->right);
        }
    }
    return result;
}

std::vector<std::string> pathsToLeaves(Node *root) 
{
    std::vector<std::string> result;

    if (root == nullptr) 
    {
        return result;
    }

    char rootChar = root->data;

    for (std::string word : pathsToLeaves(root->left)) 
    {
        word.insert(word.begin(), rootChar);
        result.push_back(word);
    }

    for (std::string word : pathsToLeaves(root->right)) 
    {
        word.insert(word.begin(), rootChar);
        result.push_back(word);
    }

    return result;
}

bool find(Node *root, const char *word) 
{
    if (root == nullptr) return word[0] == '\0';

    return root->data == word[0] &&
           (find(root->left, word + 1) ||
            find(root->right, word + 1));
}

int main() 
{
    Node *A = new Node{'a', nullptr, nullptr};
    Node *C = new Node{'c', nullptr, nullptr};
    Node *D = new Node{'d', nullptr, nullptr};
    Node *E = new Node{'e', nullptr, nullptr};
    Node *B = new Node{'b', A, C};
    Node *F = new Node{'b', D, nullptr};
    Node *root = new Node{'r', F, B};

    std::vector<std::string> res = pathsToLeaves(root);
    for (auto i : res) 
    {
        std::cout << i << " ";
    }

    return 0;
}