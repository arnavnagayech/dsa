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

void dfs(Node* root, vector<int> &inorder)
{
    if (root == NULL)
        return;

    dfs(root->left,inorder);
    inorder.push_back(root->data);
    dfs(root->right,inorder);
}

vector<int> InorderTraversal(Node* root)
{
    vector<int> inorder;
    dfs(root,inorder);

    return inorder;
}

int main()
{
    struct Node *root= new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> arr = InorderTraversal(root);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}