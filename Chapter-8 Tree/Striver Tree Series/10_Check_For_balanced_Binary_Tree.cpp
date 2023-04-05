#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data=val;
        left=right=NULL;
    }
};

int dfsHeight(Node *root)
{

    if (root == NULL)
        return 0;

    int leftHeight = dfsHeight(root->left);

    if (leftHeight == -1)
        return -1;

    int rightHeight = dfsHeight(root->right);

    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node *root)
{
    if (dfsHeight(root)!= -1)
        return true;
    
    return false;
}

int main()
{
    struct Node *root= new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    bool balanced = isBalanced(root);

    cout << "Balanced Binary Tree: " << balanced << endl;

    return 0;
}