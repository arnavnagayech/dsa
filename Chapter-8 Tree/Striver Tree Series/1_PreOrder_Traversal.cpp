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

void dfs(Node* root, vector<int> &preorder)
{
    if (root == NULL)
        return;

    preorder.push_back(root->data);
    dfs(root->left,preorder);
    dfs(root->right,preorder);

}
vector<int> preorderTraversal(Node* root)
{
    vector<int> preorder;
    dfs(root,preorder);

    return preorder;
}

int main()
{
    struct Node *root= new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> arr = preorderTraversal(root);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}